/*	$NetBSD: coda_subr.c,v 1.33 2024/05/17 23:57:46 thorpej Exp $	*/

/*
 *
 *             Coda: an Experimental Distributed File System
 *                              Release 3.1
 *
 *           Copyright (c) 1987-1998 Carnegie Mellon University
 *                          All Rights Reserved
 *
 * Permission  to  use, copy, modify and distribute this software and its
 * documentation is hereby granted,  provided  that  both  the  copyright
 * notice  and  this  permission  notice  appear  in  all  copies  of the
 * software, derivative works or  modified  versions,  and  any  portions
 * thereof, and that both notices appear in supporting documentation, and
 * that credit is given to Carnegie Mellon University  in  all  documents
 * and publicity pertaining to direct or indirect use of this code or its
 * derivatives.
 *
 * CODA IS AN EXPERIMENTAL SOFTWARE SYSTEM AND IS  KNOWN  TO  HAVE  BUGS,
 * SOME  OF  WHICH MAY HAVE SERIOUS CONSEQUENCES.  CARNEGIE MELLON ALLOWS
 * FREE USE OF THIS SOFTWARE IN ITS "AS IS" CONDITION.   CARNEGIE  MELLON
 * DISCLAIMS  ANY  LIABILITY  OF  ANY  KIND  FOR  ANY  DAMAGES WHATSOEVER
 * RESULTING DIRECTLY OR INDIRECTLY FROM THE USE OF THIS SOFTWARE  OR  OF
 * ANY DERIVATIVE WORK.
 *
 * Carnegie  Mellon  encourages  users  of  this  software  to return any
 * improvements or extensions that  they  make,  and  to  grant  Carnegie
 * Mellon the rights to redistribute these changes without encumbrance.
 *
 * 	@(#) coda/coda_subr.c,v 1.1.1.1 1998/08/29 21:26:45 rvb Exp $
 */

/*
 * Mach Operating System
 * Copyright (c) 1989 Carnegie-Mellon University
 * All rights reserved.  The CMU software License Agreement specifies
 * the terms and conditions for use and redistribution.
 */

/*
 * This code was written for the Coda file system at Carnegie Mellon
 * University.  Contributers include David Steere, James Kistler, and
 * M. Satyanarayanan.  */

/* NOTES: rvb
 * 1.	Added coda_unmounting to mark all cnodes as being UNMOUNTING.  This has to
 *	 be done before dounmount is called.  Because some of the routines that
 *	 dounmount calls before coda_unmounted might try to force flushes to venus.
 *	 The vnode pager does this.
 * 2.	coda_unmounting marks all cnodes scanning coda_cache.
 * 3.	cfs_checkunmounting (under DEBUG) checks all cnodes by chasing the vnodes
 *	 under the /coda mount point.
 * 4.	coda_cacheprint (under DEBUG) prints names with vnode/cnode address
 */

#include <sys/cdefs.h>
__KERNEL_RCSID(0, "$NetBSD: coda_subr.c,v 1.33 2024/05/17 23:57:46 thorpej Exp $");

#include <sys/param.h>
#include <sys/systm.h>
#include <sys/proc.h>
#include <sys/select.h>
#include <sys/mount.h>
#include <sys/kauth.h>

#include <coda/coda.h>
#include <coda/cnode.h>
#include <coda/coda_subr.h>
#include <coda/coda_namecache.h>

int codadebug = 0;
int coda_printf_delay = 0;  /* in microseconds */
int coda_vnop_print_entry = 0;
int coda_vfsop_print_entry = 0;

#ifdef CODA_COMPAT_5
#define coda_hash(fid) \
    (((fid)->Volume + (fid)->Vnode) & (CODA_CACHESIZE-1))
#define IS_DIR(cnode)        (cnode.Vnode & 0x1)
#else
#define coda_hash(fid) \
    (coda_f2i(fid) & (CODA_CACHESIZE-1))
#define IS_DIR(cnode)        (cnode.opaque[2] & 0x1)
#endif

struct vnode *coda_ctlvp;

/*
 * Lookup a cnode by fid. If the cnode is dying, it is bogus so skip it.
 * The cnode is returned locked with the vnode referenced.
 */
struct cnode *
coda_find(CodaFid *fid)
{
	int i;
	struct vnode *vp;
	struct cnode *cp;

	for (i = 0; i < NVCODA; i++) {
		if (!coda_mnttbl[i].mi_started)
			continue;
		if (vcache_get(coda_mnttbl[i].mi_vfsp,
		    fid, sizeof(CodaFid), &vp) != 0)
			continue;
		mutex_enter(vp->v_interlock);
		cp = VTOC(vp);
		if (vp->v_type == VNON || cp == NULL || IS_UNMOUNTING(cp)) {
			mutex_exit(vp->v_interlock);
			vrele(vp);
			continue;
		}
		mutex_enter(&cp->c_lock);
		mutex_exit(vp->v_interlock);

		return cp;
	}

	return NULL;
}

/*
 * Iterate over all nodes attached to coda mounts.
 */
static void
coda_iterate(bool (*f)(void *, struct vnode *), void *cl)
{
	int i;
	struct vnode_iterator *marker;
	struct vnode *vp;

	for (i = 0; i < NVCODA; i++) { 
		if (coda_mnttbl[i].mi_vfsp == NULL)
			continue;
		vfs_vnode_iterator_init(coda_mnttbl[i].mi_vfsp, &marker);
		while ((vp = vfs_vnode_iterator_next(marker, f, cl)) != NULL)
			vrele(vp);
		vfs_vnode_iterator_destroy(marker);
	}
}

/*
 * coda_kill is called as a side effect to vcopen. To prevent any
 * cnodes left around from an earlier run of a venus or warden from
 * causing problems with the new instance, mark any outstanding cnodes
 * as dying. Future operations on these cnodes should fail (excepting
 * coda_inactive of course!). Since multiple venii/wardens can be
 * running, only kill the cnodes for a particular entry in the
 * coda_mnttbl. -- DCS 12/1/94 */

static bool
coda_kill_selector(void *cl, struct vnode *vp)
{
	int *count = cl;

	(*count)++;

	return false;
}

int
coda_kill(struct mount *whoIam, enum dc_status dcstat)
{
	int count = 0;
	struct vnode_iterator *marker;

	/*
	 * Algorithm is as follows:
	 *     Second, flush whatever vnodes we can from the name cache.
	 */

	/* This is slightly overkill, but should work. Eventually it'd be
	 * nice to only flush those entries from the namecache that
	 * reference a vnode in this vfs.  */
	coda_nc_flush(dcstat);


	vfs_vnode_iterator_init(whoIam, &marker);
	vfs_vnode_iterator_next(marker, coda_kill_selector, &count);
	vfs_vnode_iterator_destroy(marker);

	return count;
}

/*
 * There are two reasons why a cnode may be in use, it may be in the
 * name cache or it may be executing.
 */
static bool
coda_flush_selector(void *cl, struct vnode *vp)
{
	struct cnode *cp = VTOC(vp);

	if (cp != NULL && !IS_DIR(cp->c_fid)) /* only files can be executed */
		coda_vmflush(cp);

	return false;
}
void
coda_flush(enum dc_status dcstat)
{

    coda_clstat.ncalls++;
    coda_clstat.reqs[CODA_FLUSH]++;

    coda_nc_flush(dcstat);	    /* flush files from the name cache */

    coda_iterate(coda_flush_selector, NULL);
}

/*
 * As a debugging measure, print out any cnodes that lived through a
 * name cache flush.
 */
static bool
coda_testflush_selector(void *cl, struct vnode *vp)
{
	struct cnode *cp = VTOC(vp);

	if (cp != NULL)
		myprintf(("Live cnode fid %s count %d\n",
		     coda_f2s(&cp->c_fid), vrefcnt(CTOV(cp))));

	return false;
}
void
coda_testflush(void)
{

	coda_iterate(coda_testflush_selector, NULL);
}

/*
 *     First, step through all cnodes and mark them unmounting.
 *         NetBSD kernels may try to fsync them now that venus
 *         is dead, which would be a bad thing.
 *
 */
static bool
coda_unmounting_selector(void *cl, struct vnode *vp)
{
	struct cnode *cp = VTOC(vp);

	if (cp)
		cp->c_flags |= C_UNMOUNTING;

	return false;
}
void
coda_unmounting(struct mount *whoIam)
{
	struct vnode_iterator *marker;

	vfs_vnode_iterator_init(whoIam, &marker);
	vfs_vnode_iterator_next(marker, coda_unmounting_selector, NULL);
	vfs_vnode_iterator_destroy(marker);
}

#ifdef	DEBUG
static bool
coda_checkunmounting_selector(void *cl, struct vnode *vp)
{
	struct cnode *cp = VTOC(vp);

	if (cp && !(cp->c_flags & C_UNMOUNTING)) {
		printf("vp %p, cp %p missed\n", vp, cp);
		cp->c_flags |= C_UNMOUNTING;
	}

	return false;
}
void
coda_checkunmounting(struct mount *mp)
{
	struct vnode_iterator *marker;

	vfs_vnode_iterator_init(mp, &marker);
	vfs_vnode_iterator_next(marker, coda_checkunmounting_selector, NULL);
	vfs_vnode_iterator_destroy(marker);
}

void
coda_cacheprint(struct mount *whoIam)
{
	struct vnode *vp;
	struct vnode_iterator *marker;
	int count = 0;

	printf("coda_cacheprint: coda_ctlvp %p, cp %p", coda_ctlvp, VTOC(coda_ctlvp));
	coda_nc_name(VTOC(coda_ctlvp));
	printf("\n");

	vfs_vnode_iterator_init(whoIam, &marker);
	while ((vp = vfs_vnode_iterator_next(marker, NULL, NULL)) != NULL) {
		printf("coda_cacheprint: vp %p, cp %p", vp, VTOC(vp));
		coda_nc_name(VTOC(vp));
		printf("\n");
		count++;
		vrele(vp);
	}
	printf("coda_cacheprint: count %d\n", count);
	vfs_vnode_iterator_destroy(marker);
}
#endif

/*
 * There are 6 cases where invalidations occur. The semantics of each
 * is listed here.
 *
 * CODA_FLUSH     -- flush all entries from the name cache and the cnode cache.
 * CODA_PURGEUSER -- flush all entries from the name cache for a specific user
 *                  This call is a result of token expiration.
 *
 * The next two are the result of callbacks on a file or directory.
 * CODA_ZAPDIR    -- flush the attributes for the dir from its cnode.
 *                  Zap all children of this directory from the namecache.
 * CODA_ZAPFILE   -- flush the attributes for a file.
 *
 * The fifth is a result of Venus detecting an inconsistent file.
 * CODA_PURGEFID  -- flush the attribute for the file
 *                  If it is a dir (odd vnode), purge its
 *                  children from the namecache
 *                  remove the file from the namecache.
 *
 * The sixth allows Venus to replace local fids with global ones
 * during reintegration.
 *
 * CODA_REPLACE -- replace one CodaFid with another throughout the name cache
 */

int handleDownCall(int opcode, union outputArgs *out)
{
    int error;

    /* Handle invalidate requests. */
    switch (opcode) {
      case CODA_FLUSH : {

	  coda_flush(IS_DOWNCALL);

	  CODADEBUG(CODA_FLUSH,coda_testflush();)    /* print remaining cnodes */
	      return(0);
      }

      case CODA_PURGEUSER : {
	  coda_clstat.ncalls++;
	  coda_clstat.reqs[CODA_PURGEUSER]++;

	  /* XXX - need to prevent fsync's */
#ifdef CODA_COMPAT_5
	  coda_nc_purge_user(out->coda_purgeuser.cred.cr_uid, IS_DOWNCALL);
#else
	  coda_nc_purge_user(out->coda_purgeuser.uid, IS_DOWNCALL);
#endif
	  return(0);
      }

      case CODA_ZAPFILE : {
	  struct cnode *cp;

	  error = 0;
	  coda_clstat.ncalls++;
	  coda_clstat.reqs[CODA_ZAPFILE]++;

	  cp = coda_find(&out->coda_zapfile.Fid);
	  if (cp != NULL) {
	      cp->c_flags &= ~C_VATTR;
	      if (CTOV(cp)->v_iflag & VI_TEXT)
		  error = coda_vmflush(cp);
	      CODADEBUG(CODA_ZAPFILE, myprintf((
		    "zapfile: fid = %s, refcnt = %d, error = %d\n",
		    coda_f2s(&cp->c_fid), vrefcnt(CTOV(cp)) - 1, error)););
	      if (vrefcnt(CTOV(cp)) == 1) {
		  cp->c_flags |= C_PURGING;
	      }
	      mutex_exit(&cp->c_lock);
	      vrele(CTOV(cp));
	  }

	  return(error);
      }

      case CODA_ZAPDIR : {
	  struct cnode *cp;

	  coda_clstat.ncalls++;
	  coda_clstat.reqs[CODA_ZAPDIR]++;

	  cp = coda_find(&out->coda_zapdir.Fid);
	  if (cp != NULL) {
	      cp->c_flags &= ~C_VATTR;
	      coda_nc_zapParentfid(&out->coda_zapdir.Fid, IS_DOWNCALL);

	      CODADEBUG(CODA_ZAPDIR, myprintf((
		    "zapdir: fid = %s, refcnt = %d\n",
		    coda_f2s(&cp->c_fid), vrefcnt(CTOV(cp)) - 1)););
	      if (vrefcnt(CTOV(cp)) == 1) {
		  cp->c_flags |= C_PURGING;
	      }
	      mutex_exit(&cp->c_lock);
	      vrele(CTOV(cp));
	  }

	  return(0);
      }

      case CODA_PURGEFID : {
	  struct cnode *cp;

	  error = 0;
	  coda_clstat.ncalls++;
	  coda_clstat.reqs[CODA_PURGEFID]++;

	  cp = coda_find(&out->coda_purgefid.Fid);
	  if (cp != NULL) {
	      if (IS_DIR(out->coda_purgefid.Fid)) { /* Vnode is a directory */
		  coda_nc_zapParentfid(&out->coda_purgefid.Fid,
				     IS_DOWNCALL);
	      }
	      cp->c_flags &= ~C_VATTR;
	      coda_nc_zapfid(&out->coda_purgefid.Fid, IS_DOWNCALL);
	      if (!(IS_DIR(out->coda_purgefid.Fid))
		  && (CTOV(cp)->v_iflag & VI_TEXT)) {

		  error = coda_vmflush(cp);
	      }
	      CODADEBUG(CODA_PURGEFID, myprintf((
			 "purgefid: fid = %s, refcnt = %d, error = %d\n",
			 coda_f2s(&cp->c_fid), vrefcnt(CTOV(cp)) - 1, error)););
	      if (vrefcnt(CTOV(cp)) == 1) {
		  cp->c_flags |= C_PURGING;
	      }
	      mutex_exit(&cp->c_lock);
	      vrele(CTOV(cp));
	  }
	  return(error);
      }

      case CODA_REPLACE : {
	  struct cnode *cp = NULL;

	  coda_clstat.ncalls++;
	  coda_clstat.reqs[CODA_REPLACE]++;

	  cp = coda_find(&out->coda_replace.OldFid);
	  if (cp != NULL) {
	      error = vcache_rekey_enter(CTOV(cp)->v_mount, CTOV(cp),
		  &out->coda_replace.OldFid, sizeof(CodaFid),
		  &out->coda_replace.NewFid, sizeof(CodaFid));
	      if (error) {
		  mutex_exit(&cp->c_lock);
		  vrele(CTOV(cp));
		  return error;
	      }
	      cp->c_fid = out->coda_replace.NewFid;
	      vcache_rekey_exit(CTOV(cp)->v_mount, CTOV(cp),
		  &out->coda_replace.OldFid, sizeof(CodaFid),
		  &cp->c_fid, sizeof(CodaFid));

	      CODADEBUG(CODA_REPLACE, myprintf((
			"replace: oldfid = %s, newfid = %s, cp = %p\n",
			coda_f2s(&out->coda_replace.OldFid),
			coda_f2s(&cp->c_fid), cp));)
	      mutex_exit(&cp->c_lock);
	      vrele(CTOV(cp));
	  }
	  return (0);
      }
      default:
      	myprintf(("handleDownCall: unknown opcode %d\n", opcode));
	return (EINVAL);
    }
}

/* coda_grab_vnode: lives in either cfs_mach.c or cfs_nbsd.c */

int
coda_vmflush(struct cnode *cp)
{
    return 0;
}


/*
 * kernel-internal debugging switches
 */

void coda_debugon(void)
{
    codadebug = -1;
    coda_nc_debug = -1;
    coda_vnop_print_entry = 1;
    coda_psdev_print_entry = 1;
    coda_vfsop_print_entry = 1;
}

void coda_debugoff(void)
{
    codadebug = 0;
    coda_nc_debug = 0;
    coda_vnop_print_entry = 0;
    coda_psdev_print_entry = 0;
    coda_vfsop_print_entry = 0;
}

/* How to print a ucred */
void
coda_print_cred(kauth_cred_t cred)
{

	uint16_t ngroups;
	int i;

	myprintf(("ref %d\tuid %d\n", kauth_cred_getrefcnt(cred),
		 kauth_cred_geteuid(cred)));

	ngroups = kauth_cred_ngroups(cred);
	for (i=0; i < ngroups; i++)
		myprintf(("\tgroup %d: (%d)\n", i, kauth_cred_group(cred, i)));
	myprintf(("\n"));

}

/*
 * Utilities used by both client and server
 * Standard levels:
 * 0) no debugging
 * 1) hard failures
 * 2) soft failures
 * 3) current test software
 * 4) main procedure entry points
 * 5) main procedure exit points
 * 6) utility procedure entry points
 * 7) utility procedure exit points
 * 8) obscure procedure entry points
 * 9) obscure procedure exit points
 * 10) random stuff
 * 11) all <= 1
 * 12) all <= 2
 * 13) all <= 3
 * ...
 */

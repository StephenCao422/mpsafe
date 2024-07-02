/*	$NetBSD: mcount.c,v 1.18 2024/02/23 13:32:28 christos Exp $	*/

/*
 * Copyright (c) 2003, 2004 Wasabi Systems, Inc.
 * All rights reserved.
 *
 * Written by Nathan J. Williams for Wasabi Systems, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed for the NetBSD Project by
 *	Wasabi Systems, Inc.
 * 4. The name of Wasabi Systems, Inc. may not be used to endorse
 *    or promote products derived from this software without specific prior
 *    written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY WASABI SYSTEMS, INC. ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL WASABI SYSTEMS, INC
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/*-
 * Copyright (c) 1983, 1992, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifdef _KERNEL_OPT
#include "opt_multiprocessor.h"
#endif

/* If building a standalone libkern, don't include mcount. */
#if (!defined(_KERNEL) || defined(GPROF)) && !defined(_STANDALONE)

#include <sys/cdefs.h>
#if !defined(lint) && !defined(_KERNEL) && defined(LIBC_SCCS)
#if 0
static char sccsid[] = "@(#)mcount.c	8.1 (Berkeley) 6/4/93";
#else
__RCSID("$NetBSD: mcount.c,v 1.18 2024/02/23 13:32:28 christos Exp $");
#endif
#endif

#include <sys/param.h>
#include <sys/gmon.h>
#include <sys/lock.h>
#include <sys/proc.h>

#ifndef _KERNEL
#include "reentrant.h"
#endif

#if defined(_REENTRANT) && !defined(_RUMPKERNEL)
extern thread_key_t _gmonkey;
extern struct gmonparam _gmondummy;
struct gmonparam *_m_gmon_alloc(void);
#endif

_MCOUNT_DECL(u_long, u_long)
#ifdef _KERNEL
    __attribute__((__no_instrument_function__))
#endif
    __used;

/* XXX: make these interfaces */
#ifdef _RUMPKERNEL
#undef MCOUNT_ENTER
#define MCOUNT_ENTER
#undef MCOUNT_EXIT
#define MCOUNT_EXIT
#undef MCOUNT
#define MCOUNT
#endif

/*
 * mcount is called on entry to each function compiled with the profiling
 * switch set.  _mcount(), which is declared in a machine-dependent way
 * with _MCOUNT_DECL, does the actual work and is either inlined into a
 * C routine or called by an assembly stub.  In any case, this magic is
 * taken care of by the MCOUNT definition in <machine/profile.h>.
 *
 * _mcount updates data structures that represent traversals of the
 * program's call graph edges.  frompc and selfpc are the return
 * address and function address that represents the given call graph edge.
 * 
 * Note: the original BSD code used the same variable (frompcindex) for
 * both frompcindex and frompc.  Any reasonable, modern compiler will
 * perform this optimization.
 */
/* _mcount; may be static, inline, etc */
/*LINTED unused*/
_MCOUNT_DECL(u_long frompc, u_long selfpc)
{
	u_short *frompcindex;
	struct tostruct *top, *prevtop;
	struct gmonparam *p;
	long toindex;
#if defined(_KERNEL) && !defined(_RUMPKERNEL)
	int s;
#endif

#if defined(_REENTRANT) && !defined(_KERNEL) && !defined(_RUMPKERNEL)
	if (__isthreaded) {
		/* prevent re-entry via thr_getspecific */
		if (_gmonparam.state != GMON_PROF_ON)
			return;
		_gmonparam.state = GMON_PROF_BUSY;
		p = thr_getspecific(_gmonkey);
		if (p == NULL) {
			/* Prevent recursive calls while allocating */
			thr_setspecific(_gmonkey, &_gmondummy);
			p = _m_gmon_alloc();
		}
		_gmonparam.state = GMON_PROF_ON;
	} else
#endif
		p = &_gmonparam;
	/*
	 * check that we are profiling
	 * and that we aren't recursively invoked.
	 */
	if (p->state != GMON_PROF_ON)
		return;
#if defined(_KERNEL) && !defined(_RUMPKERNEL)
	MCOUNT_ENTER;
#ifdef MULTIPROCESSOR
	p = curcpu()->ci_gmon;
	if (p == NULL || p->state != GMON_PROF_ON) {
		MCOUNT_EXIT;
		return;
	}
#endif
#endif
	p->state = GMON_PROF_BUSY;
	/*
	 * check that frompcindex is a reasonable pc value.
	 * for example:	signal catchers get called from the stack,
	 *		not from text space.  too bad.
	 */
	frompc -= p->lowpc;
	if (frompc > p->textsize)
		goto done;

#if (HASHFRACTION & (HASHFRACTION - 1)) == 0
	if (p->hashfraction == HASHFRACTION)
		frompcindex =
		    &p->froms[
		    (size_t)(frompc / (HASHFRACTION * sizeof(*p->froms)))];
	else
#endif
		frompcindex =
		    &p->froms[
		    (size_t)(frompc / (p->hashfraction * sizeof(*p->froms)))];
	toindex = *frompcindex;
	if (toindex == 0) {
		/*
		 *	first time traversing this arc
		 */
		toindex = ++p->tos[0].link;
		if (toindex >= p->tolimit)
			/* halt further profiling */
			goto overflow;

		*frompcindex = (u_short)toindex;
		top = &p->tos[(size_t)toindex];
		top->selfpc = selfpc;
		top->count = 1;
		top->link = 0;
		goto done;
	}
	top = &p->tos[(size_t)toindex];
	if (top->selfpc == selfpc) {
		/*
		 * arc at front of chain; usual case.
		 */
		top->count++;
		goto done;
	}
	/*
	 * have to go looking down chain for it.
	 * top points to what we are looking at,
	 * prevtop points to previous top.
	 * we know it is not at the head of the chain.
	 */
	for (; /* goto done */; ) {
		if (top->link == 0) {
			/*
			 * top is end of the chain and none of the chain
			 * had top->selfpc == selfpc.
			 * so we allocate a new tostruct
			 * and link it to the head of the chain.
			 */
			toindex = ++p->tos[0].link;
			if (toindex >= p->tolimit)
				goto overflow;

			top = &p->tos[(size_t)toindex];
			top->selfpc = selfpc;
			top->count = 1;
			top->link = *frompcindex;
			*frompcindex = (u_short)toindex;
			goto done;
		}
		/*
		 * otherwise, check the next arc on the chain.
		 */
		prevtop = top;
		top = &p->tos[top->link];
		if (top->selfpc == selfpc) {
			/*
			 * there it is.
			 * increment its count
			 * move it to the head of the chain.
			 */
			top->count++;
			toindex = prevtop->link;
			prevtop->link = top->link;
			top->link = *frompcindex;
			*frompcindex = (u_short)toindex;
			goto done;
		}
	}
done:
	p->state = GMON_PROF_ON;
#if defined(_KERNEL) && !defined(_RUMPKERNEL)
	MCOUNT_EXIT;
#endif
	return;

overflow:
	p->state = GMON_PROF_ERROR;
#if defined(_KERNEL) && !defined(_RUMPKERNEL)
	MCOUNT_EXIT;
#endif
	return;
}

#ifdef MCOUNT
/*
 * Actual definition of mcount function.  Defined in <machine/profile.h>,
 * which is included by <sys/gmon.h>.
 */
MCOUNT
#endif

#if defined(_KERNEL) && !defined(_RUMPKERNEL) && defined(MULTIPROCESSOR)
void _gmonparam_merge(struct gmonparam *, struct gmonparam *);

void
_gmonparam_merge(struct gmonparam *p, struct gmonparam *q)
{
	u_long fromindex;
	u_short *frompcindex, qtoindex, toindex;
	u_long selfpc;
	u_long endfrom;
	long count;
	struct tostruct *top;
	int i;

	count = q->kcountsize / sizeof(*q->kcount);
	for (i = 0; i < count; i++)
		p->kcount[i] += q->kcount[i];

	endfrom = (q->fromssize / sizeof(*q->froms));
	for (fromindex = 0; fromindex < endfrom; fromindex++) {
		if (q->froms[fromindex] == 0)
			continue;
		for (qtoindex = q->froms[fromindex]; qtoindex != 0;
		     qtoindex = q->tos[qtoindex].link) {
			selfpc = q->tos[qtoindex].selfpc;
			count = q->tos[qtoindex].count;
			/* cribbed from mcount */
			frompcindex = &p->froms[fromindex];
			toindex = *frompcindex;
			if (toindex == 0) {
				/*
				 * first time traversing this arc
				 */
				toindex = ++p->tos[0].link;
				if (toindex >= p->tolimit)
					/* halt further profiling */
					goto overflow;

				*frompcindex = (u_short)toindex;
				top = &p->tos[(size_t)toindex];
				top->selfpc = selfpc;
				top->count = count;
				top->link = 0;
				goto done;
			}
			top = &p->tos[(size_t)toindex];
			if (top->selfpc == selfpc) {
				/*
				 * arc at front of chain; usual case.
				 */
				top->count+= count;
				goto done;
			}
			/*
			 * have to go looking down chain for it.
			 * top points to what we are looking at,
			 * we know it is not at the head of the chain.
			 */
			for (; /* goto done */; ) {
				if (top->link == 0) {
					/*
					 * top is end of the chain and
					 * none of the chain had
					 * top->selfpc == selfpc.  so
					 * we allocate a new tostruct
					 * and link it to the head of
					 * the chain.
					 */
					toindex = ++p->tos[0].link;
					if (toindex >= p->tolimit)
						goto overflow;

					top = &p->tos[(size_t)toindex];
					top->selfpc = selfpc;
					top->count = count;
					top->link = *frompcindex;
					*frompcindex = (u_short)toindex;
					goto done;
				}
				/*
				 * otherwise, check the next arc on the chain.
				 */
				top = &p->tos[top->link];
				if (top->selfpc == selfpc) {
					/*
					 * there it is.
					 * add to its count.
					 */
					top->count += count;
					goto done;
				}
			}

		done: ;
		}

	}
 overflow: ;

}
#endif

#endif /* (!_KERNEL || GPROF) && !_STANDALONE */
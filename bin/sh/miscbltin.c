/*	$NetBSD: miscbltin.c,v 1.54 2023/10/05 20:33:31 kre Exp $	*/

/*-
 * Copyright (c) 1991, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Kenneth Almquist.
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

#include <sys/cdefs.h>
#ifndef lint
#if 0
static char sccsid[] = "@(#)miscbltin.c	8.4 (Berkeley) 5/4/95";
#else
__RCSID("$NetBSD: miscbltin.c,v 1.54 2023/10/05 20:33:31 kre Exp $");
#endif
#endif /* not lint */

/*
 * Miscellaneous builtins.
 */

#include <sys/types.h>		/* quad_t */
#include <sys/param.h>		/* BSD4_4 */
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>

#include "shell.h"
#include "options.h"
#include "var.h"
#include "output.h"
#include "memalloc.h"
#include "error.h"
#include "builtins.h"
#include "mystring.h"
#include "redir.h"		/* for user_fd_limit */

#undef rflag



/*
 * The read builtin.
 * Backslashes escape the next char unless -r is specified.
 *
 * This uses unbuffered input, which may be avoidable in some cases.
 *
 * Note that if IFS=' :' then read x y should work so that:
 * 'a b'	x='a', y='b'
 * ' a b '	x='a', y='b'
 * ':b'		x='',  y='b'
 * ':'		x='',  y=''
 * '::'		x='',  y=''
 * ': :'	x='',  y=''
 * ':::'	x='',  y='::'
 * ':b c:'	x='',  y='b c:'
 */

int
readcmd(int argc, char **argv)
{
	char **ap;
	char c;
	char end;
	int rflag;
	char *prompt;
	const char *ifs;
	char *p;
	int startword;
	int status;
	int i;
	int is_ifs;
	int saveall = 0;
	ptrdiff_t wordlen = 0;
	char *newifs = NULL;
	struct stackmark mk;

	end = '\n';				/* record delimiter */
	rflag = 0;
	prompt = NULL;
	while ((i = nextopt("d:p:r")) != '\0') {
		switch (i) {
		case 'd':
			end = *optionarg;	/* even if '\0' */
			break;
		case 'p':
			prompt = optionarg;
			break;
		case 'r':
			rflag = 1;
			break;
		}
	}

	if (*(ap = argptr) == NULL)
		error("variable name required\n"
			"Usage: read [-r] [-p prompt] var...");

	if (prompt && isatty(0)) {
		out2str(prompt);
		flushall();
	}

	if ((ifs = bltinlookup("IFS", 1)) == NULL)
		ifs = " \t\n";

	setstackmark(&mk);
	status = 0;
	startword = 2;
	STARTSTACKSTR(p);
	for (;;) {
		if (read(0, &c, 1) != 1) {
			status = 1;
			break;
		}
		if (c == '\\' && c != end && !rflag) {
			if (read(0, &c, 1) != 1) {
				status = 1;
				break;
			}
			if (c != '\n')	/* \ \n is always just removed */
				goto wdch;
			continue;
		}
		if (c == end)
			break;
		if (c == '\0')
			continue;
		if (strchr(ifs, c))
			is_ifs = strchr(" \t\n", c) ? 1 : 2;
		else
			is_ifs = 0;

		if (startword != 0) {
			if (is_ifs == 1) {
				/* Ignore leading IFS whitespace */
				if (saveall)
					STPUTC(c, p);
				continue;
			}
			if (is_ifs == 2 && startword == 1) {
				/* Only one non-whitespace IFS per word */
				startword = 2;
				if (saveall)
					STPUTC(c, p);
				continue;
			}
		}

		if (is_ifs == 0) {
  wdch:;
			if (c == '\0')	/* always ignore attempts to input \0 */
				continue;
			/* append this character to the current variable */
			startword = 0;
			if (saveall)
				/* Not just a spare terminator */
				saveall++;
			STPUTC(c, p);
			wordlen = p - stackblock();
			continue;
		}

		/* end of variable... */
		startword = is_ifs;

		if (ap[1] == NULL) {
			/* Last variable needs all IFS chars */
			saveall++;
			STPUTC(c, p);
			continue;
		}

		if (equal(*ap, "IFS")) {
			/*
			 * we must not alter the value of IFS, as our
			 * local "ifs" var is (perhaps) pointing at it,
			 * at best we would be using data after free()
			 * the next time we reference ifs - but that mem
			 * may have been reused for something different.
			 *
			 * note that this might occur several times
			 */
			STPUTC('\0', p);
			newifs = grabstackstr(p);
		} else {
			STACKSTRNUL(p);
			setvar(*ap, stackblock(), 0);
		}
		ap++;
		STARTSTACKSTR(p);
		wordlen = 0;
	}
	STACKSTRNUL(p);

	/* Remove trailing IFS chars */
	for (; stackblock() + wordlen <= --p; *p = 0) {
		if (!strchr(ifs, *p))
			break;
		if (strchr(" \t\n", *p))
			/* Always remove whitespace */
			continue;
		if (saveall > 1)
			/* Don't remove non-whitespace unless it was naked */
			break;
	}

	/*
	 * If IFS was one of the variables named, we can finally set it now
	 * (no further references to ifs will be made)
	 */
	if (newifs != NULL)
		setvar("IFS", newifs, 0);

	/*
	 * Now we can assign to the final variable (which might
	 * also be IFS, hence the ordering here)
	 */
	setvar(*ap, stackblock(), 0);

	/* Set any remaining args to "" */
	while (*++ap != NULL)
		setvar(*ap, nullstr, 0);

	popstackmark(&mk);
	return status;
}



int
umaskcmd(int argc, char **argv)
{
	char *ap;
	mode_t mask;
	int i;
	int symbolic_mode = 0;

	while ((i = nextopt("S")) != '\0') {
		symbolic_mode = 1;
	}

	INTOFF;
	mask = umask(0);
	umask(mask);
	INTON;

	if ((ap = *argptr) == NULL) {
		if (symbolic_mode) {
			char u[4], g[4], o[4];

			i = 0;
			if ((mask & S_IRUSR) == 0)
				u[i++] = 'r';
			if ((mask & S_IWUSR) == 0)
				u[i++] = 'w';
			if ((mask & S_IXUSR) == 0)
				u[i++] = 'x';
			u[i] = '\0';

			i = 0;
			if ((mask & S_IRGRP) == 0)
				g[i++] = 'r';
			if ((mask & S_IWGRP) == 0)
				g[i++] = 'w';
			if ((mask & S_IXGRP) == 0)
				g[i++] = 'x';
			g[i] = '\0';

			i = 0;
			if ((mask & S_IROTH) == 0)
				o[i++] = 'r';
			if ((mask & S_IWOTH) == 0)
				o[i++] = 'w';
			if ((mask & S_IXOTH) == 0)
				o[i++] = 'x';
			o[i] = '\0';

			out1fmt("u=%s,g=%s,o=%s\n", u, g, o);
		} else {
			out1fmt("%.4o\n", mask);
		}
	} else {
		if (isdigit((unsigned char)*ap)) {
			int range = 0;

			mask = 0;
			do {
				if (*ap >= '8' || *ap < '0')
					error("Not a valid octal number: '%s'",
					    *argptr);
				mask = (mask << 3) + (*ap - '0');
				if (mask & ~07777)
					range = 1;
			} while (*++ap != '\0');
			if (range)
			    error("Mask constant '%s' out of range", *argptr);
			umask(mask);
		} else {
			void *set;

			INTOFF;
			if ((set = setmode(ap)) != 0) {
				mask = getmode(set, ~mask & 0777);
				ckfree(set);
			}
			INTON;
			if (!set)
				error("Cannot set mode `%s' (%s)", ap,
				    strerror(errno));

			umask(~mask & 0777);
		}
	}
	flushout(out1);
	if (io_err(out1)) {
		out2str("umask: I/O error\n");
		return 1;
	}
	return 0;
}

/*
 * ulimit builtin
 *
 * This code, originally by Doug Gwyn, Doug Kingston, Eric Gisin, and
 * Michael Rendell was ripped from pdksh 5.0.8 and hacked for use with
 * ash by J.T. Conklin.
 *
 * Public domain.
 */

struct limits {
	const char *name;
	const char *unit;
	char	option;
	int8_t	cmd;		/* all RLIMIT_xxx are <= 127 */
	unsigned short factor;	/* multiply by to get rlim_{cur,max} values */
};

#define	OPTSTRING_BASE "HSa"

static const struct limits limits[] = {
#ifdef RLIMIT_CPU
	{ "time",	"seconds",	't',	RLIMIT_CPU,	   1 },
#define	OPTSTRING_t	OPTSTRING_BASE "t"
#else
#define	OPTSTRING_t	OPTSTRING_BASE
#endif
#ifdef RLIMIT_FSIZE
	{ "file",	"blocks",	'f',	RLIMIT_FSIZE,	 512 },
#define	OPTSTRING_f	OPTSTRING_t "f"
#else
#define	OPTSTRING_f	OPTSTRING_t
#endif
#ifdef RLIMIT_DATA
	{ "data",	"kbytes",	'd',	RLIMIT_DATA,	1024 },
#define	OPTSTRING_d	OPTSTRING_f "d"
#else
#define	OPTSTRING_d	OPTSTRING_f
#endif
#ifdef RLIMIT_STACK
	{ "stack",	"kbytes",	's',	RLIMIT_STACK,	1024 },
#define	OPTSTRING_s	OPTSTRING_d "s"
#else
#define	OPTSTRING_s	OPTSTRING_d
#endif
#ifdef RLIMIT_CORE
	{ "coredump",	"blocks",	'c',	RLIMIT_CORE,	 512 },
#define	OPTSTRING_c	OPTSTRING_s "c"
#else
#define	OPTSTRING_c	OPTSTRING_s
#endif
#ifdef RLIMIT_RSS
	{ "memory",	"kbytes",	'm',	RLIMIT_RSS,	1024 },
#define	OPTSTRING_m	OPTSTRING_c "m"
#else
#define	OPTSTRING_m	OPTSTRING_c
#endif
#ifdef RLIMIT_MEMLOCK
	{ "locked memory","kbytes",	'l',	RLIMIT_MEMLOCK, 1024 },
#define	OPTSTRING_l	OPTSTRING_m "l"
#else
#define	OPTSTRING_l	OPTSTRING_m
#endif
#ifdef RLIMIT_NTHR
	{ "thread",	"threads",	'r',	RLIMIT_NTHR,       1 },
#define	OPTSTRING_r	OPTSTRING_l "r"
#else
#define	OPTSTRING_r	OPTSTRING_l
#endif
#ifdef RLIMIT_NPROC
	{ "process",	"processes",	'p',	RLIMIT_NPROC,      1 },
#define	OPTSTRING_p	OPTSTRING_r "p"
#else
#define	OPTSTRING_p	OPTSTRING_r
#endif
#ifdef RLIMIT_NOFILE
	{ "nofiles",	"descriptors",	'n',	RLIMIT_NOFILE,     1 },
#define	OPTSTRING_n	OPTSTRING_p "n"
#else
#define	OPTSTRING_n	OPTSTRING_p
#endif
#ifdef RLIMIT_VMEM
	{ "vmemory",	"kbytes",	'v',	RLIMIT_VMEM,	1024 },
#define	OPTSTRING_v	OPTSTRING_n "v"
#else
#define	OPTSTRING_v	OPTSTRING_n
#endif
#ifdef RLIMIT_SWAP
	{ "swap",	"kbytes",	'w',	RLIMIT_SWAP,	1024 },
#define	OPTSTRING_w	OPTSTRING_v "w"
#else
#define	OPTSTRING_w	OPTSTRING_v
#endif
#ifdef RLIMIT_SBSIZE
	{ "sbsize",	"bytes",	'b',	RLIMIT_SBSIZE,	   1 },
#define	OPTSTRING_b	OPTSTRING_w "b"
#else
#define	OPTSTRING_b	OPTSTRING_w
#endif
	{ NULL,		NULL,		'\0',	0,		   0 }
};
#define	OPTSTRING	OPTSTRING_b

int
ulimitcmd(int argc, char **argv)
{
	int	c;
	rlim_t val = 0;
	enum { SOFT = 0x1, HARD = 0x2 }
			how = 0, which;
	const struct limits	*l;
	int		set, all = 0;
	int		optc, what;
	struct rlimit	limit;

	what = 'f';
	while ((optc = nextopt(OPTSTRING)) != '\0')
		switch (optc) {
		case 'H':
			how |= HARD;
			break;
		case 'S':
			how |= SOFT;
			break;
		case 'a':
			all = 1;
			break;
		default:
			what = optc;
		}

	for (l = limits; l->name && l->option != what; l++)
		;
	if (!l->name)
		error("internal error (%c)", what);

	set = *argptr ? 1 : 0;
	if (set) {
		char *p = *argptr;

		if (all || argptr[1])
			error("too many arguments");
		if (how == 0)
			how = HARD | SOFT;

		if (strcmp(p, "unlimited") == 0)
			val = RLIM_INFINITY;
		else {
			val = (rlim_t) 0;

			while ((c = *p++) >= '0' && c <= '9') {
				if (val >= RLIM_INFINITY/10)
					error("%s: value overflow", *argptr);
				val = (val * 10);
				if (val >= RLIM_INFINITY - (long)(c - '0'))
					error("%s: value overflow", *argptr);
				val += (long)(c - '0');
			}
			if (c)
				error("%s: bad number", *argptr);
			if (val > RLIM_INFINITY / l->factor)
				error("%s: value overflow", *argptr);
			val *= l->factor;
		}
	} else if (how == 0)
		how = SOFT;

	if (all) {
		for (l = limits; l->name; l++) {
			getrlimit(l->cmd, &limit);
			out1fmt("%-13s (-%c %-11s)    ", l->name, l->option,
			    l->unit);

			which = how;
			while (which != 0) {
				if (which & SOFT) {
					val = limit.rlim_cur;
					which &= ~SOFT;
				} else if (which & HARD) {
					val = limit.rlim_max;
					which &= ~HARD;
				}

				if (val == RLIM_INFINITY)
					out1fmt("unlimited");
				else {
					val /= l->factor;
#ifdef BSD4_4
					out1fmt("%9lld", (long long) val);
#else
					out1fmt("%9ld", (long) val);
#endif
				}
				out1fmt("%c", which ? '\t' : '\n');
			}
		}
		goto done;
	}

	if (getrlimit(l->cmd, &limit) == -1)
		error("error getting limit (%s)", strerror(errno));
	if (set) {
		if (how & HARD)
			limit.rlim_max = val;
		if (how & SOFT)
			limit.rlim_cur = val;
		if (setrlimit(l->cmd, &limit) < 0)
			error("error setting limit (%s)", strerror(errno));
		if (l->cmd == RLIMIT_NOFILE)
			user_fd_limit = sysconf(_SC_OPEN_MAX);
	} else {
		if (how & SOFT)
			val = limit.rlim_cur;
		else if (how & HARD)
			val = limit.rlim_max;

		if (val == RLIM_INFINITY)
			out1fmt("unlimited\n");
		else
		{
			val /= l->factor;
#ifdef BSD4_4
			out1fmt("%lld\n", (long long) val);
#else
			out1fmt("%ld\n", (long) val);
#endif
		}
	}
  done:;
	flushout(out1);
	if (io_err(out1)) {
		out2str("ulimit: I/O error (stdout)\n");
		return 1;
	}
	return 0;
}
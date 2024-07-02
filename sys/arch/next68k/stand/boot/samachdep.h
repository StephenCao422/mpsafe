/*	$NetBSD: samachdep.h,v 1.2 2023/02/12 10:04:56 tsutsui Exp $	*/

/*
 * Copyright (c) 1982, 1990, 1993
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
 *
 *	@(#)samachdep.h	8.1 (Berkeley) 6/10/93
 */

#include <sys/param.h>
#include <lib/libsa/stand.h>

/* boot.c */
extern int entry_point;
extern int cpuspeed;
extern int turbo;

/* en.c */
int enstrategy(void *, int, daddr_t, size_t, void *, size_t *);
int enopen(struct open_file *, ...);
int enclose(struct open_file *);

/* machdep.c */
extern char *mg;

/* rtc.c */
void rtc_init(void);

/* sd.c */
int sdstrategy(void *, int, daddr_t, size_t, void *, size_t *);
int sdopen(struct open_file *, ...);
int sdclose(struct open_file *);

/* srt0.S */
__dead void _halt(void);

/* vers.c (generated by sys/conf/newvers_stand.sh) */
extern	char bootprog_name[], bootprog_rev[], bootprog_kernrev[];

/* build.c (generated by ${.CURDIR}/newvers.sh) */
extern int build;

/* delay constants; note all CPU cache is turned off here */
#define MHZ_25		3
#define MHZ_33		4

#define DELAY(n)							\
do {									\
	register u_int __n = (cpuspeed * (n) / 4) + 1;			\
	do {								\
		__asm("subql #1, %0" : "=r" (__n) : "0" (__n));		\
	} while (__n > 0);						\
} while (/* CONSTCOND */ 0)
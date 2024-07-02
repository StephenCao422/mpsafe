#	$NetBSD: Makefile.inc,v 1.3 2024/02/21 22:50:56 christos Exp $

.include <bsd.own.mk>

.include "${.CURDIR}/../../Makefile.inc"

TOOLS=${IDIST}/bin/tools

.PATH: ${TOOLS} ${IDIST}/doc/man

PROG=${BASE}
SRCS=${BASE}.c
MAN=${BASE}.1
# Keep things where they used to be historically
# Ideally since most utils have moved to section 1 man
# pages, we should move them to /usr/bin too. But
# those utils are only related to bind so moving them
# to /usr/bin would just add clutter.
# The following does not work, hard-code
# BINDIR= ${${BASE} == "arpaname":? /usr/bin : /usr/sbin}
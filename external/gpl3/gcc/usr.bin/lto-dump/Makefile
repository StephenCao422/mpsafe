#	$NetBSD: Makefile,v 1.3 2024/06/30 16:15:04 christos Exp $

PROG=		lto-dump
# XXX pullout from LTO_DUMP_OBJS
SRCS=		lto-lang.cc \
		lto-object.cc \
		attribs.cc \
		lto-partition.cc \
		lto-symtab.cc \
		lto-dump.cc \
		lto-common.cc \
		main.cc

BINDIR=		/usr/bin

CPPFLAGS+=	-DPREFIX=\"/usr\"

COPTS.lto-lang.cc+=	-Wno-error=stack-protector
COPTS.lto-common.cc+=	-Wno-error=stack-protector

.include "../Makefile.backend"
.include "../Makefile.target-defines"
.include "../Makefile.libcpp"
.include "../Makefile.backtrace"
.include "../Makefile.libdecnumber"

.if ${MACHINE_ARCH} == "vax" && 0
COPTS.lto-lang.c+=-O0
COPTS.lto-symtab.c+=-O0
.endif

LDADD+=	${LIBIBERTY} ${LIBMPC} ${LIBMPFR} ${LIBGMP} -lintl -lz -lm
DPADD+=	${LIBIBERTY} ${LIBMPC} ${LIBMPFR} ${LIBGMP} ${LIBINTL} ${LIBZ} ${LIBM}

.PATH: ${DIST}/gcc/lto ${DIST}/gcc ${DIST}/gcc/doc

#	$NetBSD: Makefile,v 1.12 2024/07/02 04:51:41 rin Exp $

.include <bsd.own.mk>

# crtstuff is built out of elsewhere, or not at all
SUBDIR+= libgcc .WAIT
SUBDIR+= libiberty libobjc libgomp
SUBDIR+= libbacktrace
SUBDIR+= liblto_plugin

.if (${MKLIBSTDCXX} != "no") && (${MKCXX} != "no")
SUBDIR+= libsupc++ libstdc++-v3

.if ${MKGCCCMDS} != "no"
SUBDIR+= .WAIT libasan liblsan libubsan

# TSan does not work with 32bit address space and has not been ported
# to all 64-bit architectures.
.if ${MACHINE} == "amd64"
SUBDIR+= libtsan
.endif
.endif

.endif

.include <bsd.subdir.mk>

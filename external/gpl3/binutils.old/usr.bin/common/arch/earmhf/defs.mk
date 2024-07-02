# This file is automatically generated.  DO NOT EDIT!
# Generated from: NetBSD: mknative-binutils,v 1.14 2022/12/24 20:17:46 christos Exp 
# Generated from: NetBSD: mknative.common,v 1.16 2018/04/15 15:13:37 christos Exp 
#
G_VERSION=2.39
G_DEFS=-DHAVE_CONFIG_H
G_INCLUDES=
G_PROGRAMS=size objdump ar  strings ranlib objcopy   addr2line readelf elfedit   nm-new strip-new cxxfilt bfdtest1 bfdtest2 
G_man_MANS=doc/addr2line.1  doc/ar.1  doc/dlltool.1  doc/nm.1  doc/objcopy.1  doc/objdump.1  doc/ranlib.1  doc/readelf.1  doc/size.1  doc/strings.1  doc/strip.1  doc/elfedit.1  doc/windres.1  doc/windmc.1  doc/c++filt.1
G_TEXINFOS=doc/binutils.texi
G_PKGVERSION=(NetBSD Binutils nb1)
G_REPORT_BUGS_TEXI=@uref{http://www.NetBSD.org/support/send-pr.html}
G_size_OBJECTS=size.o bucomm.o version.o filemode.o
G_size_DEPENDENCIES=./../intl/libintl.a ../libiberty/libiberty.a ../bfd/libbfd.la
G_objdump_OBJECTS=objdump.o dwarf.o prdbg.o  demanguse.o rddbg.o debug.o stabs.o  rdcoff.o bucomm.o version.o filemode.o  elfcomm.o
G_objdump_DEPENDENCIES=./../intl/libintl.a ../libiberty/libiberty.a ../bfd/libbfd.la ../opcodes/libopcodes.la ../libctf/libctf.la 
G_ar_OBJECTS=arparse.o arlex.o ar.o  not-ranlib.o arsup.o rename.o  binemul.o emul_vanilla.o bucomm.o version.o filemode.o
G_ar_DEPENDENCIES=./../intl/libintl.a ../libiberty/libiberty.a ../bfd/libbfd.la
G_strings_OBJECTS=strings.o bucomm.o version.o filemode.o
G_strings_DEPENDENCIES=./../intl/libintl.a ../libiberty/libiberty.a ../bfd/libbfd.la
G_ranlib_OBJECTS=ar.o is-ranlib.o arparse.o  arlex.o arsup.o rename.o  binemul.o emul_vanilla.o bucomm.o version.o filemode.o
G_ranlib_DEPENDENCIES=./../intl/libintl.a ../libiberty/libiberty.a ../bfd/libbfd.la
G_objcopy_OBJECTS=objcopy.o not-strip.o  rename.o rddbg.o debug.o stabs.o  rdcoff.o wrstabs.o bucomm.o version.o filemode.o
G_objcopy_DEPENDENCIES=./../intl/libintl.a ../libiberty/libiberty.a ../bfd/libbfd.la
G_addr2line_OBJECTS=addr2line.o bucomm.o version.o filemode.o
G_addr2line_DEPENDENCIES=./../intl/libintl.a ../libiberty/libiberty.a ../bfd/libbfd.la
G_readelf_OBJECTS=readelf.o version.o  unwind-ia64.o dwarf.o demanguse.o  elfcomm.o
G_readelf_DEPENDENCIES=./../intl/libintl.a ../libiberty/libiberty.a ../libctf/libctf-nobfd.la
G_elfedit_OBJECTS=elfedit.o version.o  elfcomm.o
G_elfedit_DEPENDENCIES=./../intl/libintl.a ../libiberty/libiberty.a
G_nm_new_OBJECTS=nm.o demanguse.o bucomm.o version.o filemode.o
G_nm_new_DEPENDENCIES=./../intl/libintl.a ../libiberty/libiberty.a ../bfd/libbfd.la
G_strip_new_OBJECTS=objcopy.o is-strip.o  rename.o rddbg.o debug.o stabs.o  rdcoff.o wrstabs.o bucomm.o version.o filemode.o
G_strip_new_DEPENDENCIES=./../intl/libintl.a ../libiberty/libiberty.a ../bfd/libbfd.la
G_cxxfilt_OBJECTS=cxxfilt.o bucomm.o version.o filemode.o
G_cxxfilt_DEPENDENCIES=./../intl/libintl.a ../libiberty/libiberty.a ../bfd/libbfd.la
G_bfdtest1_OBJECTS=bfdtest1.o
G_bfdtest1_DEPENDENCIES=./../intl/libintl.a ../libiberty/libiberty.a ../bfd/libbfd.la
G_bfdtest2_OBJECTS=bfdtest2.o
G_bfdtest2_DEPENDENCIES=./../intl/libintl.a ../libiberty/libiberty.a ../bfd/libbfd.la
# This file is automatically generated.  DO NOT EDIT!
# Generated from: NetBSD: mknative-gcc,v 1.118 2024/02/21 08:24:46 mrg Exp 
# Generated from: NetBSD: mknative.common,v 1.16 2018/04/15 15:13:37 christos Exp 
#
G_BUILD_EARLY_SUPPORT=
G_BUILD_ERRORS=build-errors.o
G_BUILD_PRINT=
G_BUILD_RTL=build-rtl.o read-rtl.o build-ggc-none.o vec.o min-insn-modes.o gensupport.o build-print-rtl.o hash-table.o sort.o
G_BUILD_SUPPORT=
G_BUILD_VARRAY=
G_BUILD_MD=read-md.o
G_ALL_CFLAGS=   -DIN_GCC    -W -Wall -Wno-narrowing -Wwrite-strings -Wcast-qual -Wstrict-prototypes -Wmissing-prototypes -Wmissing-format-attribute -Woverloaded-virtual -pedantic -Wno-long-long -Wno-variadic-macros -Wno-overlength-strings -Wold-style-definition -Wc++-compat   -DHAVE_CONFIG_H
G_ALL_CPPFLAGS=-I. -I. -I${GNUHOSTDIST}/gcc -I${GNUHOSTDIST}/gcc/. -I${GNUHOSTDIST}/gcc/../include -I./../intl -I${GNUHOSTDIST}/gcc/../libcpp/include -I${GNUHOSTDIST}/gcc/../libcody     -I${GNUHOSTDIST}/gcc/../libdecnumber -I${GNUHOSTDIST}/gcc/../libdecnumber/dpd -I../libdecnumber -I${GNUHOSTDIST}/gcc/../libbacktrace  
G_C_AND_OBJC_OBJS=attribs.o c/c-errors.o c/c-decl.o c/c-typeck.o c/c-convert.o c/c-aux-info.o c/c-objc-common.o c/c-parser.o c/c-fold.o c/gimple-parser.o c-family/c-common.o c-family/c-cppbuiltin.o c-family/c-dump.o c-family/c-format.o c-family/c-gimplify.o c-family/c-indentation.o c-family/c-lex.o c-family/c-omp.o c-family/c-opts.o c-family/c-pch.o c-family/c-ppoutput.o c-family/c-pragma.o c-family/c-pretty-print.o c-family/c-semantics.o c-family/c-ada-spec.o c-family/c-ubsan.o c-family/known-headers.o c-family/c-attribs.o c-family/c-warn.o c-family/c-spellcheck.o aarch64-c.o default-c.o
G_C_OBJS=c/c-lang.o c-family/stub-objc.o attribs.o c/c-errors.o c/c-decl.o c/c-typeck.o c/c-convert.o c/c-aux-info.o c/c-objc-common.o c/c-parser.o c/c-fold.o c/gimple-parser.o c-family/c-common.o c-family/c-cppbuiltin.o c-family/c-dump.o c-family/c-format.o c-family/c-gimplify.o c-family/c-indentation.o c-family/c-lex.o c-family/c-omp.o c-family/c-opts.o c-family/c-pch.o c-family/c-ppoutput.o c-family/c-pragma.o c-family/c-pretty-print.o c-family/c-semantics.o c-family/c-ada-spec.o c-family/c-ubsan.o c-family/known-headers.o c-family/c-attribs.o c-family/c-warn.o c-family/c-spellcheck.o aarch64-c.o default-c.o
G_CCCP_OBJS=
G_GCC_OBJS=gcc.o gcc-main.o ggc-none.o
G_GCOV_OBJS=gcov.o json.o
G_GCOV_DUMP_OBJS=gcov-dump.o
G_GXX_OBJS=gcc.o gcc-main.o ggc-none.o cp/g++spec.o
G_GTM_H=tm.h      options.h ${GNUHOSTDIST}/gcc/config/aarch64/biarchlp64.h ${GNUHOSTDIST}/gcc/config/aarch64/aarch64.h ${GNUHOSTDIST}/gcc/config/dbxelf.h ${GNUHOSTDIST}/gcc/config/elfos.h ${GNUHOSTDIST}/gcc/config/netbsd.h ${GNUHOSTDIST}/gcc/config/netbsd-stdint.h ${GNUHOSTDIST}/gcc/config/netbsd-elf.h ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-elf.h ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-errata.h ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-netbsd.h ${GNUHOSTDIST}/gcc/config/initfini-array.h ${GNUHOSTDIST}/gcc/defaults.h insn-constants.h
G_PROTO_OBJS=
G_INCLUDES=-I. -I. -I${GNUHOSTDIST}/gcc -I${GNUHOSTDIST}/gcc/. -I${GNUHOSTDIST}/gcc/../include -I./../intl -I${GNUHOSTDIST}/gcc/../libcpp/include -I${GNUHOSTDIST}/gcc/../libcody     -I${GNUHOSTDIST}/gcc/../libdecnumber -I${GNUHOSTDIST}/gcc/../libdecnumber/dpd -I../libdecnumber -I${GNUHOSTDIST}/gcc/../libbacktrace 
G_md_file=${GNUHOSTDIST}/gcc/common.md ${GNUHOSTDIST}/gcc/config/aarch64/aarch64.md
G_OBJC_OBJS=objc/objc-lang.o objc/objc-act.o hash-table.o objc/objc-runtime-shared-support.o objc/objc-gnu-runtime-abi-01.o objc/objc-next-runtime-abi-01.o objc/objc-next-runtime-abi-02.o objc/objc-encoding.o objc/objc-map.o
G_OBJS=gimple-match.o generic-match.o insn-attrtab.o insn-automata.o insn-dfatab.o insn-emit.o insn-extract.o insn-latencytab.o insn-modes.o insn-opinit.o insn-output.o insn-peep.o insn-preds.o insn-recog.o insn-enums.o ggc-page.o adjust-alignment.o alias.o alloc-pool.o auto-inc-dec.o auto-profile.o bb-reorder.o bitmap.o builtins.o caller-save.o calls.o ccmp.o cfg.o cfganal.o cfgbuild.o cfgcleanup.o cfgexpand.o cfghooks.o cfgloop.o cfgloopanal.o cfgloopmanip.o cfgrtl.o ctfc.o ctfout.o btfout.o symtab.o symtab-thunks.o symtab-clones.o cgraph.o cgraphbuild.o cgraphunit.o cgraphclones.o combine.o combine-stack-adj.o compare-elim.o context.o convert.o coroutine-passes.o coverage.o cppbuiltin.o cppdefault.o cprop.o cse.o cselib.o data-streamer.o data-streamer-in.o data-streamer-out.o dbxout.o dbgcnt.o dce.o ddg.o debug.o df-core.o df-problems.o df-scan.o dfp.o digraph.o dojump.o dominance.o domwalk.o double-int.o dse.o dumpfile.o dwarf2asm.o dwarf2cfi.o dwarf2ctf.o dwarf2out.o early-remat.o emit-rtl.o et-forest.o except.o explow.o expmed.o expr.o fibonacci_heap.o file-prefix-map.o final.o fixed-value.o fold-const.o fold-const-call.o function.o function-abi.o function-tests.o fwprop.o gcc-rich-location.o gcse.o gcse-common.o ggc-common.o ggc-tests.o gimple.o gimple-array-bounds.o gimple-builder.o gimple-expr.o gimple-if-to-switch.o gimple-iterator.o gimple-fold.o gimple-harden-conditionals.o gimple-laddress.o gimple-loop-interchange.o gimple-loop-jam.o gimple-loop-versioning.o gimple-low.o gimple-predicate-analysis.o gimple-pretty-print.o gimple-range.o gimple-range-cache.o gimple-range-edge.o gimple-range-fold.o gimple-range-gori.o gimple-range-trace.o gimple-ssa-backprop.o gimple-ssa-evrp.o gimple-ssa-evrp-analyze.o gimple-ssa-isolate-paths.o gimple-ssa-nonnull-compare.o gimple-ssa-split-paths.o gimple-ssa-store-merging.o gimple-ssa-strength-reduction.o gimple-ssa-sprintf.o gimple-ssa-warn-access.o gimple-ssa-warn-alloca.o gimple-ssa-warn-restrict.o gimple-streamer-in.o gimple-streamer-out.o gimple-walk.o gimple-warn-recursion.o gimplify.o gimplify-me.o godump.o graph.o graphds.o graphviz.o graphite.o graphite-isl-ast-to-gimple.o graphite-dependences.o graphite-optimize-isl.o graphite-poly.o graphite-scop-detection.o graphite-sese-to-poly.o gtype-desc.o haifa-sched.o hash-map-tests.o hash-set-tests.o hw-doloop.o hwint.o ifcvt.o ree.o inchash.o incpath.o init-regs.o internal-fn.o ipa-cp.o ipa-sra.o ipa-devirt.o ipa-fnsummary.o ipa-polymorphic-call.o ipa-split.o ipa-inline.o ipa-comdats.o ipa-free-lang-data.o ipa-visibility.o ipa-inline-analysis.o ipa-inline-transform.o ipa-modref.o ipa-modref-tree.o ipa-predicate.o ipa-profile.o ipa-prop.o ipa-param-manipulation.o ipa-pure-const.o ipa-icf.o ipa-icf-gimple.o ipa-reference.o ipa-ref.o ipa-utils.o ipa.o ira.o ira-build.o ira-costs.o ira-conflicts.o ira-color.o ira-emit.o ira-lives.o jump.o langhooks.o lcm.o lists.o loop-doloop.o loop-init.o loop-invariant.o loop-iv.o loop-unroll.o lower-subreg.o lra.o lra-assigns.o lra-coalesce.o lra-constraints.o lra-eliminations.o lra-lives.o lra-remat.o lra-spills.o lto-cgraph.o lto-streamer.o lto-streamer-in.o lto-streamer-out.o lto-section-in.o lto-section-out.o lto-opts.o lto-compress.o mcf.o mode-switching.o modulo-sched.o multiple_target.o omp-offload.o omp-expand.o omp-general.o omp-low.o omp-oacc-kernels-decompose.o omp-oacc-neuter-broadcast.o omp-simd-clone.o opt-problem.o optabs.o optabs-libfuncs.o optabs-query.o optabs-tree.o optinfo.o optinfo-emit-json.o options-save.o opts-global.o ordered-hash-map-tests.o passes.o plugin.o pointer-query.o postreload-gcse.o postreload.o predict.o print-rtl.o print-rtl-function.o print-tree.o profile.o profile-count.o range.o range-op.o read-md.o read-rtl.o read-rtl-function.o real.o realmpfr.o recog.o reg-stack.o regcprop.o reginfo.o regrename.o regstat.o regsub.o reload.o reload1.o reorg.o resource.o rtl-error.o rtl-ssa/accesses.o rtl-ssa/blocks.o rtl-ssa/changes.o rtl-ssa/functions.o rtl-ssa/insns.o rtl-tests.o rtl.o rtlhash.o rtlanal.o rtlhooks.o rtx-vector-builder.o run-rtl-passes.o sched-deps.o sched-ebb.o sched-rgn.o sel-sched-ir.o sel-sched-dump.o sel-sched.o selftest-rtl.o selftest-run-tests.o sese.o shrink-wrap.o simplify-rtx.o sparseset.o spellcheck.o spellcheck-tree.o splay-tree-utils.o sreal.o stack-ptr-mod.o statistics.o stmt.o stor-layout.o store-motion.o streamer-hooks.o stringpool.o substring-locations.o target-globals.o targhooks.o timevar.o toplev.o tracer.o trans-mem.o tree-affine.o asan.o tsan.o ubsan.o sanopt.o sancov.o tree-call-cdce.o tree-cfg.o tree-cfgcleanup.o tree-chrec.o tree-complex.o tree-data-ref.o tree-dfa.o tree-diagnostic.o tree-diagnostic-path.o tree-dump.o tree-eh.o tree-emutls.o tree-if-conv.o tree-inline.o tree-into-ssa.o tree-iterator.o tree-loop-distribution.o tree-nested.o tree-nrv.o tree-object-size.o tree-outof-ssa.o tree-parloops.o tree-phinodes.o tree-predcom.o tree-pretty-print.o tree-profile.o tree-scalar-evolution.o tree-sra.o tree-switch-conversion.o tree-ssa-address.o tree-ssa-alias.o tree-ssa-ccp.o tree-ssa-coalesce.o tree-ssa-copy.o tree-ssa-dce.o tree-ssa-dom.o tree-ssa-dse.o tree-ssa-forwprop.o tree-ssa-ifcombine.o tree-ssa-live.o tree-ssa-loop-ch.o tree-ssa-loop-im.o tree-ssa-loop-ivcanon.o tree-ssa-loop-ivopts.o tree-ssa-loop-manip.o tree-ssa-loop-niter.o tree-ssa-loop-prefetch.o tree-ssa-loop-split.o tree-ssa-loop-unswitch.o tree-ssa-loop.o tree-ssa-math-opts.o tree-ssa-operands.o gimple-range-path.o tree-ssa-phiopt.o tree-ssa-phiprop.o tree-ssa-pre.o tree-ssa-propagate.o tree-ssa-reassoc.o tree-ssa-sccvn.o tree-ssa-scopedtables.o tree-ssa-sink.o tree-ssa-strlen.o tree-ssa-structalias.o tree-ssa-tail-merge.o tree-ssa-ter.o tree-ssa-threadbackward.o tree-ssa-threadedge.o tree-ssa-threadupdate.o tree-ssa-uncprop.o tree-ssa-uninit.o tree-ssa.o tree-ssanames.o tree-stdarg.o tree-streamer.o tree-streamer-in.o tree-streamer-out.o tree-tailcall.o tree-vect-generic.o gimple-isel.o tree-vect-patterns.o tree-vect-data-refs.o tree-vect-stmts.o tree-vect-loop.o tree-vect-loop-manip.o tree-vect-slp.o tree-vect-slp-patterns.o tree-vectorizer.o tree-vector-builder.o tree-vrp.o tree.o tristate.o typed-splay-tree.o valtrack.o value-pointer-equiv.o value-query.o value-range.o value-range-equiv.o value-relation.o value-prof.o var-tracking.o varasm.o varpool.o vec-perm-indices.o vmsdbgout.o vr-values.o vtable-verify.o warning-control.o web.o wide-int.o wide-int-print.o xcoffout.o aarch64.o analyzer/analysis-plan.o analyzer/analyzer.o analyzer/analyzer-logging.o analyzer/analyzer-pass.o analyzer/analyzer-selftests.o analyzer/bar-chart.o analyzer/call-info.o analyzer/call-string.o analyzer/checker-path.o analyzer/complexity.o analyzer/constraint-manager.o analyzer/diagnostic-manager.o analyzer/engine.o analyzer/feasible-graph.o analyzer/function-set.o analyzer/pending-diagnostic.o analyzer/program-point.o analyzer/program-state.o analyzer/region.o analyzer/region-model.o analyzer/region-model-asm.o analyzer/region-model-impl-calls.o analyzer/region-model-manager.o analyzer/region-model-reachability.o analyzer/sm.o analyzer/sm-file.o analyzer/sm-malloc.o analyzer/sm-pattern-test.o analyzer/sm-sensitive.o analyzer/sm-signal.o analyzer/sm-taint.o analyzer/state-purge.o analyzer/store.o analyzer/supergraph.o analyzer/svalue.o analyzer/trimmed-graph.o aarch64-builtins.o aarch-common.o aarch64-sve-builtins.o aarch64-sve-builtins-shapes.o aarch64-sve-builtins-base.o aarch64-sve-builtins-sve2.o cortex-a57-fma-steering.o aarch64-speculation.o falkor-tag-collision-avoidance.o aarch64-bti-insert.o aarch64-cc-fusion.o netbsd.o host-netbsd.o
G_out_file=${GNUHOSTDIST}/gcc/config/aarch64/aarch64.cc
G_version=12.4.0
G_BUILD_PREFIX=
G_RTL_H=coretypes.h insn-modes.h signop.h wide-int.h wide-int-print.h insn-modes-inline.h machmode.h mode-classes.def double-int.h rtl.h rtl.def reg-notes.def insn-notes.def ${GNUHOSTDIST}/gcc/../libcpp/include/line-map.h input.h real.h statistics.h vec.h statistics.h ggc.h gtype-desc.h statistics.h fixed-value.h alias.h ${GNUHOSTDIST}/gcc/../include/hashtab.h flags.h flag-types.h options.h flag-types.h  ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-opts.h ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-cores.def ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-arches.def ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-fusion-pairs.def ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-tuning-flags.def genrtl.h
G_RTL_BASE_H=coretypes.h insn-modes.h signop.h wide-int.h wide-int-print.h insn-modes-inline.h machmode.h mode-classes.def double-int.h rtl.h rtl.def reg-notes.def insn-notes.def ${GNUHOSTDIST}/gcc/../libcpp/include/line-map.h input.h real.h statistics.h vec.h statistics.h ggc.h gtype-desc.h statistics.h fixed-value.h alias.h ${GNUHOSTDIST}/gcc/../include/hashtab.h
G_TREE_H=tree.h tree-core.h coretypes.h insn-modes.h signop.h wide-int.h wide-int-print.h insn-modes-inline.h machmode.h mode-classes.def double-int.h all-tree.def tree.def c-family/c-common.def ${GNUHOSTDIST}/gcc/cp/cp-tree.def ${GNUHOSTDIST}/gcc/d/d-tree.def ${GNUHOSTDIST}/gcc/objc/objc-tree.def builtins.def sync-builtins.def omp-builtins.def gtm-builtins.def sanitizer.def ${GNUHOSTDIST}/gcc/../libcpp/include/line-map.h input.h statistics.h vec.h statistics.h ggc.h gtype-desc.h statistics.h treestruct.def ${GNUHOSTDIST}/gcc/../include/hashtab.h alias.h ${GNUHOSTDIST}/gcc/../libcpp/include/symtab.h ${GNUHOSTDIST}/gcc/../include/obstack.h flags.h flag-types.h options.h flag-types.h  ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-opts.h ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-cores.def ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-arches.def ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-fusion-pairs.def ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-tuning-flags.def real.h fixed-value.h  tree-check.h
G_BASIC_BLOCK_H=basic-block.h predict.h predict.def vec.h statistics.h ggc.h gtype-desc.h statistics.h function.h ${GNUHOSTDIST}/gcc/../include/hashtab.h tm.h      options.h ${GNUHOSTDIST}/gcc/config/aarch64/biarchlp64.h ${GNUHOSTDIST}/gcc/config/aarch64/aarch64.h ${GNUHOSTDIST}/gcc/config/dbxelf.h ${GNUHOSTDIST}/gcc/config/elfos.h ${GNUHOSTDIST}/gcc/config/netbsd.h ${GNUHOSTDIST}/gcc/config/netbsd-stdint.h ${GNUHOSTDIST}/gcc/config/netbsd-elf.h ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-elf.h ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-errata.h ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-netbsd.h ${GNUHOSTDIST}/gcc/config/initfini-array.h ${GNUHOSTDIST}/gcc/defaults.h insn-constants.h insn-flags.h options.h flag-types.h  ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-opts.h ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-cores.def ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-arches.def ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-fusion-pairs.def ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-tuning-flags.def ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-cores.def hard-reg-set.h vec.h statistics.h ggc.h gtype-desc.h statistics.h ${GNUHOSTDIST}/gcc/../libcpp/include/line-map.h input.h cfg-flags.def cfghooks.h profile-count.h
G_GCC_H=gcc.h version.h diagnostic-core.h ${GNUHOSTDIST}/gcc/../libcpp/include/line-map.h input.h bversion.h diagnostic.def
G_D_TARGET_DEF=d/d-target.def target-hooks-macros.h
G_GTFILES_SRCDIR=
G_GTFILES_FILES_FILES=
G_GTFILES_FILES_LANGS=
G_GTFILES=${GNUHOSTDIST}/gcc/../libcpp/include/line-map.h ${GNUHOSTDIST}/gcc/../libcpp/include/cpplib.h ${GNUHOSTDIST}/gcc/input.h ${GNUHOSTDIST}/gcc/coretypes.h auto-host.h ${GNUHOSTDIST}/gcc/../include/ansidecl.h options.h ${GNUHOSTDIST}/gcc/config/aarch64/biarchlp64.h ${GNUHOSTDIST}/gcc/config/aarch64/aarch64.h ${GNUHOSTDIST}/gcc/config/dbxelf.h ${GNUHOSTDIST}/gcc/config/elfos.h ${GNUHOSTDIST}/gcc/config/netbsd.h ${GNUHOSTDIST}/gcc/config/netbsd-stdint.h ${GNUHOSTDIST}/gcc/config/netbsd-elf.h ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-elf.h ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-errata.h ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-netbsd.h ${GNUHOSTDIST}/gcc/config/initfini-array.h ${GNUHOSTDIST}/gcc/defaults.h ${GNUHOSTDIST}/gcc/../include/hashtab.h ${GNUHOSTDIST}/gcc/../include/splay-tree.h ${GNUHOSTDIST}/gcc/bitmap.h ${GNUHOSTDIST}/gcc/wide-int.h ${GNUHOSTDIST}/gcc/alias.h ${GNUHOSTDIST}/gcc/coverage.cc  ${GNUHOSTDIST}/gcc/rtl.h ${GNUHOSTDIST}/gcc/optabs.h ${GNUHOSTDIST}/gcc/tree.h ${GNUHOSTDIST}/gcc/tree-core.h ${GNUHOSTDIST}/gcc/libfuncs.h ${GNUHOSTDIST}/gcc/../libcpp/include/symtab.h ${GNUHOSTDIST}/gcc/../include/obstack.h ${GNUHOSTDIST}/gcc/real.h ${GNUHOSTDIST}/gcc/function.h ${GNUHOSTDIST}/gcc/insn-addr.h ${GNUHOSTDIST}/gcc/hwint.h ${GNUHOSTDIST}/gcc/fixed-value.h ${GNUHOSTDIST}/gcc/function-abi.h ${GNUHOSTDIST}/gcc/output.h ${GNUHOSTDIST}/gcc/cfgloop.h ${GNUHOSTDIST}/gcc/cfg.h ${GNUHOSTDIST}/gcc/profile-count.h ${GNUHOSTDIST}/gcc/cselib.h ${GNUHOSTDIST}/gcc/basic-block.h  ${GNUHOSTDIST}/gcc/ipa-ref.h ${GNUHOSTDIST}/gcc/cgraph.h ${GNUHOSTDIST}/gcc/symtab-thunks.h ${GNUHOSTDIST}/gcc/symtab-thunks.cc ${GNUHOSTDIST}/gcc/symtab-clones.h ${GNUHOSTDIST}/gcc/reload.h ${GNUHOSTDIST}/gcc/caller-save.cc ${GNUHOSTDIST}/gcc/symtab.cc ${GNUHOSTDIST}/gcc/alias.cc ${GNUHOSTDIST}/gcc/bitmap.cc ${GNUHOSTDIST}/gcc/cselib.cc ${GNUHOSTDIST}/gcc/cgraph.cc ${GNUHOSTDIST}/gcc/ipa-prop.cc ${GNUHOSTDIST}/gcc/ipa-cp.cc ${GNUHOSTDIST}/gcc/ipa-utils.h ${GNUHOSTDIST}/gcc/ipa-param-manipulation.h ${GNUHOSTDIST}/gcc/ipa-sra.cc ${GNUHOSTDIST}/gcc/dbxout.cc ${GNUHOSTDIST}/gcc/ipa-modref.h ${GNUHOSTDIST}/gcc/ipa-modref.cc ${GNUHOSTDIST}/gcc/ipa-modref-tree.h ${GNUHOSTDIST}/gcc/signop.h ${GNUHOSTDIST}/gcc/diagnostic-spec.h ${GNUHOSTDIST}/gcc/diagnostic-spec.cc ${GNUHOSTDIST}/gcc/dwarf2out.h ${GNUHOSTDIST}/gcc/dwarf2asm.cc ${GNUHOSTDIST}/gcc/dwarf2cfi.cc ${GNUHOSTDIST}/gcc/dwarf2ctf.cc ${GNUHOSTDIST}/gcc/dwarf2out.cc ${GNUHOSTDIST}/gcc/ctfc.h ${GNUHOSTDIST}/gcc/ctfout.cc ${GNUHOSTDIST}/gcc/btfout.cc ${GNUHOSTDIST}/gcc/tree-vect-generic.cc ${GNUHOSTDIST}/gcc/gimple-isel.cc ${GNUHOSTDIST}/gcc/dojump.cc ${GNUHOSTDIST}/gcc/emit-rtl.h ${GNUHOSTDIST}/gcc/emit-rtl.cc ${GNUHOSTDIST}/gcc/except.h ${GNUHOSTDIST}/gcc/explow.cc ${GNUHOSTDIST}/gcc/expr.cc ${GNUHOSTDIST}/gcc/expr.h ${GNUHOSTDIST}/gcc/function.cc ${GNUHOSTDIST}/gcc/except.cc ${GNUHOSTDIST}/gcc/ggc-tests.cc ${GNUHOSTDIST}/gcc/gcse.cc ${GNUHOSTDIST}/gcc/godump.cc ${GNUHOSTDIST}/gcc/lists.cc ${GNUHOSTDIST}/gcc/optabs-libfuncs.cc ${GNUHOSTDIST}/gcc/profile.cc ${GNUHOSTDIST}/gcc/mcf.cc ${GNUHOSTDIST}/gcc/reg-stack.cc ${GNUHOSTDIST}/gcc/cfgrtl.cc ${GNUHOSTDIST}/gcc/stor-layout.cc ${GNUHOSTDIST}/gcc/stringpool.cc ${GNUHOSTDIST}/gcc/tree.cc ${GNUHOSTDIST}/gcc/varasm.cc ${GNUHOSTDIST}/gcc/gimple.h ${GNUHOSTDIST}/gcc/gimple-ssa.h ${GNUHOSTDIST}/gcc/tree-ssanames.cc ${GNUHOSTDIST}/gcc/tree-eh.cc ${GNUHOSTDIST}/gcc/tree-ssa-address.cc ${GNUHOSTDIST}/gcc/tree-cfg.cc ${GNUHOSTDIST}/gcc/tree-ssa-loop-ivopts.cc ${GNUHOSTDIST}/gcc/tree-dfa.cc ${GNUHOSTDIST}/gcc/tree-iterator.cc ${GNUHOSTDIST}/gcc/gimple-expr.cc ${GNUHOSTDIST}/gcc/tree-chrec.h ${GNUHOSTDIST}/gcc/tree-scalar-evolution.cc ${GNUHOSTDIST}/gcc/tree-ssa-operands.h ${GNUHOSTDIST}/gcc/tree-profile.cc ${GNUHOSTDIST}/gcc/tree-nested.cc ${GNUHOSTDIST}/gcc/omp-offload.h ${GNUHOSTDIST}/gcc/omp-general.cc ${GNUHOSTDIST}/gcc/omp-low.cc ${GNUHOSTDIST}/gcc/targhooks.cc ${GNUHOSTDIST}/gcc/config/aarch64/aarch64.cc ${GNUHOSTDIST}/gcc/passes.cc ${GNUHOSTDIST}/gcc/cgraphclones.cc ${GNUHOSTDIST}/gcc/tree-phinodes.cc ${GNUHOSTDIST}/gcc/tree-ssa-alias.h ${GNUHOSTDIST}/gcc/tree-ssanames.h ${GNUHOSTDIST}/gcc/tree-vrp.h ${GNUHOSTDIST}/gcc/value-range.h ${GNUHOSTDIST}/gcc/ipa-prop.h ${GNUHOSTDIST}/gcc/trans-mem.cc ${GNUHOSTDIST}/gcc/lto-streamer.h ${GNUHOSTDIST}/gcc/target-globals.h ${GNUHOSTDIST}/gcc/ipa-predicate.h ${GNUHOSTDIST}/gcc/ipa-fnsummary.h ${GNUHOSTDIST}/gcc/vtable-verify.cc ${GNUHOSTDIST}/gcc/asan.cc ${GNUHOSTDIST}/gcc/ubsan.cc ${GNUHOSTDIST}/gcc/tsan.cc ${GNUHOSTDIST}/gcc/sanopt.cc ${GNUHOSTDIST}/gcc/sancov.cc ${GNUHOSTDIST}/gcc/ipa-devirt.cc ${GNUHOSTDIST}/gcc/internal-fn.h ${GNUHOSTDIST}/gcc/calls.cc ${GNUHOSTDIST}/gcc/omp-general.h ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-builtins.cc ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-sve-builtins.h ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-sve-builtins.cc [c] ${GNUHOSTDIST}/gcc/c/c-lang.cc ${GNUHOSTDIST}/gcc/c/c-tree.h ${GNUHOSTDIST}/gcc/c/c-decl.cc ${GNUHOSTDIST}/gcc/c-family/c-common.cc ${GNUHOSTDIST}/gcc/c-family/c-common.h ${GNUHOSTDIST}/gcc/c-family/c-objc.h ${GNUHOSTDIST}/gcc/c-family/c-cppbuiltin.cc ${GNUHOSTDIST}/gcc/c-family/c-pragma.h ${GNUHOSTDIST}/gcc/c-family/c-pragma.cc ${GNUHOSTDIST}/gcc/c-family/c-format.cc ${GNUHOSTDIST}/gcc/c/c-objc-common.cc ${GNUHOSTDIST}/gcc/c/c-parser.h ${GNUHOSTDIST}/gcc/c/c-parser.cc ${GNUHOSTDIST}/gcc/c/c-lang.h [cp] ${GNUHOSTDIST}/gcc/cp/name-lookup.h ${GNUHOSTDIST}/gcc/cp/cp-tree.h ${GNUHOSTDIST}/gcc/c-family/c-common.h ${GNUHOSTDIST}/gcc/c-family/c-objc.h ${GNUHOSTDIST}/gcc/c-family/c-pragma.h ${GNUHOSTDIST}/gcc/cp/decl.h ${GNUHOSTDIST}/gcc/cp/parser.h ${GNUHOSTDIST}/gcc/c-family/c-common.cc ${GNUHOSTDIST}/gcc/c-family/c-format.cc ${GNUHOSTDIST}/gcc/c-family/c-cppbuiltin.cc ${GNUHOSTDIST}/gcc/c-family/c-pragma.cc ${GNUHOSTDIST}/gcc/cp/call.cc ${GNUHOSTDIST}/gcc/cp/class.cc ${GNUHOSTDIST}/gcc/cp/constexpr.cc ${GNUHOSTDIST}/gcc/cp/constraint.cc ${GNUHOSTDIST}/gcc/cp/coroutines.cc ${GNUHOSTDIST}/gcc/cp/cp-gimplify.cc ${GNUHOSTDIST}/gcc/cp/cp-lang.cc ${GNUHOSTDIST}/gcc/cp/cp-objcp-common.cc ${GNUHOSTDIST}/gcc/cp/decl.cc ${GNUHOSTDIST}/gcc/cp/decl2.cc ${GNUHOSTDIST}/gcc/cp/except.cc ${GNUHOSTDIST}/gcc/cp/friend.cc ${GNUHOSTDIST}/gcc/cp/init.cc ${GNUHOSTDIST}/gcc/cp/lambda.cc ${GNUHOSTDIST}/gcc/cp/lex.cc ${GNUHOSTDIST}/gcc/cp/logic.cc ${GNUHOSTDIST}/gcc/cp/mangle.cc ${GNUHOSTDIST}/gcc/cp/method.cc ${GNUHOSTDIST}/gcc/cp/module.cc ${GNUHOSTDIST}/gcc/cp/name-lookup.cc ${GNUHOSTDIST}/gcc/cp/parser.cc ${GNUHOSTDIST}/gcc/cp/pt.cc ${GNUHOSTDIST}/gcc/cp/rtti.cc ${GNUHOSTDIST}/gcc/cp/semantics.cc ${GNUHOSTDIST}/gcc/cp/tree.cc ${GNUHOSTDIST}/gcc/cp/typeck2.cc ${GNUHOSTDIST}/gcc/cp/vtable-class-hierarchy.cc  [d] ${GNUHOSTDIST}/gcc/d/d-tree.h ${GNUHOSTDIST}/gcc/d/d-builtins.cc ${GNUHOSTDIST}/gcc/d/d-lang.cc ${GNUHOSTDIST}/gcc/d/typeinfo.cc [fortran] ${GNUHOSTDIST}/gcc/fortran/f95-lang.cc ${GNUHOSTDIST}/gcc/fortran/trans-decl.cc ${GNUHOSTDIST}/gcc/fortran/trans-intrinsic.cc ${GNUHOSTDIST}/gcc/fortran/trans-io.cc ${GNUHOSTDIST}/gcc/fortran/trans-stmt.cc ${GNUHOSTDIST}/gcc/fortran/trans-types.cc ${GNUHOSTDIST}/gcc/fortran/trans-types.h ${GNUHOSTDIST}/gcc/fortran/trans.h ${GNUHOSTDIST}/gcc/fortran/trans-const.h [jit] ${GNUHOSTDIST}/gcc/jit/dummy-frontend.cc [lto] ${GNUHOSTDIST}/gcc/lto/lto-tree.h ${GNUHOSTDIST}/gcc/lto/lto-lang.cc ${GNUHOSTDIST}/gcc/lto/lto.cc ${GNUHOSTDIST}/gcc/lto/lto.h ${GNUHOSTDIST}/gcc/lto/lto-common.h ${GNUHOSTDIST}/gcc/lto/lto-common.cc ${GNUHOSTDIST}/gcc/lto/lto-dump.cc [objc] ${GNUHOSTDIST}/gcc/objc/objc-map.h ${GNUHOSTDIST}/gcc/c-family/c-objc.h ${GNUHOSTDIST}/gcc/objc/objc-act.h ${GNUHOSTDIST}/gcc/objc/objc-act.cc ${GNUHOSTDIST}/gcc/objc/objc-runtime-shared-support.cc ${GNUHOSTDIST}/gcc/objc/objc-gnu-runtime-abi-01.cc ${GNUHOSTDIST}/gcc/objc/objc-next-runtime-abi-01.cc ${GNUHOSTDIST}/gcc/objc/objc-next-runtime-abi-02.cc ${GNUHOSTDIST}/gcc/c/c-parser.h ${GNUHOSTDIST}/gcc/c/c-parser.cc ${GNUHOSTDIST}/gcc/c/c-tree.h ${GNUHOSTDIST}/gcc/c/c-decl.cc ${GNUHOSTDIST}/gcc/c/c-lang.h ${GNUHOSTDIST}/gcc/c/c-objc-common.cc ${GNUHOSTDIST}/gcc/c-family/c-common.cc ${GNUHOSTDIST}/gcc/c-family/c-common.h ${GNUHOSTDIST}/gcc/c-family/c-cppbuiltin.cc ${GNUHOSTDIST}/gcc/c-family/c-pragma.h ${GNUHOSTDIST}/gcc/c-family/c-pragma.cc ${GNUHOSTDIST}/gcc/c-family/c-format.cc [objcp] ${GNUHOSTDIST}/gcc/cp/name-lookup.h ${GNUHOSTDIST}/gcc/cp/cp-tree.h ${GNUHOSTDIST}/gcc/c-family/c-common.h ${GNUHOSTDIST}/gcc/c-family/c-objc.h ${GNUHOSTDIST}/gcc/c-family/c-pragma.h ${GNUHOSTDIST}/gcc/cp/decl.h ${GNUHOSTDIST}/gcc/cp/parser.h ${GNUHOSTDIST}/gcc/c-family/c-common.cc ${GNUHOSTDIST}/gcc/c-family/c-format.cc ${GNUHOSTDIST}/gcc/c-family/c-cppbuiltin.cc ${GNUHOSTDIST}/gcc/c-family/c-pragma.cc ${GNUHOSTDIST}/gcc/cp/call.cc ${GNUHOSTDIST}/gcc/cp/class.cc ${GNUHOSTDIST}/gcc/cp/constexpr.cc ${GNUHOSTDIST}/gcc/cp/constraint.cc ${GNUHOSTDIST}/gcc/cp/coroutines.cc ${GNUHOSTDIST}/gcc/cp/cp-gimplify.cc ${GNUHOSTDIST}/gcc/objcp/objcp-lang.cc ${GNUHOSTDIST}/gcc/cp/cp-objcp-common.cc ${GNUHOSTDIST}/gcc/cp/decl.cc ${GNUHOSTDIST}/gcc/cp/decl2.cc ${GNUHOSTDIST}/gcc/cp/except.cc ${GNUHOSTDIST}/gcc/cp/friend.cc ${GNUHOSTDIST}/gcc/cp/init.cc ${GNUHOSTDIST}/gcc/cp/lambda.cc ${GNUHOSTDIST}/gcc/cp/lex.cc ${GNUHOSTDIST}/gcc/cp/logic.cc ${GNUHOSTDIST}/gcc/cp/mangle.cc ${GNUHOSTDIST}/gcc/cp/method.cc ${GNUHOSTDIST}/gcc/cp/module.cc ${GNUHOSTDIST}/gcc/cp/name-lookup.cc ${GNUHOSTDIST}/gcc/cp/parser.cc ${GNUHOSTDIST}/gcc/cp/pt.cc ${GNUHOSTDIST}/gcc/cp/rtti.cc ${GNUHOSTDIST}/gcc/cp/semantics.cc ${GNUHOSTDIST}/gcc/cp/tree.cc ${GNUHOSTDIST}/gcc/cp/typeck2.cc ${GNUHOSTDIST}/gcc/cp/vtable-class-hierarchy.cc ${GNUHOSTDIST}/gcc/objc/objc-act.h ${GNUHOSTDIST}/gcc/objc/objc-map.h ${GNUHOSTDIST}/gcc/objc/objc-act.cc ${GNUHOSTDIST}/gcc/objc/objc-gnu-runtime-abi-01.cc ${GNUHOSTDIST}/gcc/objc/objc-next-runtime-abi-01.cc ${GNUHOSTDIST}/gcc/objc/objc-next-runtime-abi-02.cc ${GNUHOSTDIST}/gcc/objc/objc-runtime-shared-support.cc 
G_GTFILES_LANG_DIR_NAMES=
G_HASH_TABLE_H=${GNUHOSTDIST}/gcc/../include/hashtab.h hash-table.h ggc.h gtype-desc.h statistics.h
G_NOEXCEPTION_FLAGS=-fno-exceptions -fno-rtti -fasynchronous-unwind-tables
G_NATIVE_SYSTEM_HEADER_DIR=/usr/include
G_tm_defines=LIBC_GLIBC=1 LIBC_UCLIBC=2 LIBC_BIONIC=3 LIBC_MUSL=4 TARGET_BIG_ENDIAN_DEFAULT=1 TARGET_FIX_ERR_A53_835769_DEFAULT=1 TARGET_FIX_ERR_A53_843419_DEFAULT=1
G_host_xm_file=
G_host_xm_defines=
G_tm_p_file=
G_target_cpu_default=
G_TM_H=tm.h      options.h ${GNUHOSTDIST}/gcc/config/aarch64/biarchlp64.h ${GNUHOSTDIST}/gcc/config/aarch64/aarch64.h ${GNUHOSTDIST}/gcc/config/dbxelf.h ${GNUHOSTDIST}/gcc/config/elfos.h ${GNUHOSTDIST}/gcc/config/netbsd.h ${GNUHOSTDIST}/gcc/config/netbsd-stdint.h ${GNUHOSTDIST}/gcc/config/netbsd-elf.h ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-elf.h ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-errata.h ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-netbsd.h ${GNUHOSTDIST}/gcc/config/initfini-array.h ${GNUHOSTDIST}/gcc/defaults.h insn-constants.h insn-flags.h options.h flag-types.h  ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-opts.h ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-cores.def ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-arches.def ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-fusion-pairs.def ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-tuning-flags.def ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-cores.def
G_ALL_OPT_FILES=${GNUHOSTDIST}/gcc/d/lang.opt ${GNUHOSTDIST}/gcc/fortran/lang.opt ${GNUHOSTDIST}/gcc/lto/lang.opt ${GNUHOSTDIST}/gcc/c-family/c.opt ${GNUHOSTDIST}/gcc/common.opt ${GNUHOSTDIST}/gcc/params.opt ${GNUHOSTDIST}/gcc/analyzer/analyzer.opt ${GNUHOSTDIST}/gcc/config/aarch64/aarch64.opt ${GNUHOSTDIST}/gcc/config/netbsd.opt ${GNUHOSTDIST}/gcc/config/netbsd-elf.opt
G_tm_file_list=options.h ${GNUHOSTDIST}/gcc/config/aarch64/biarchlp64.h ${GNUHOSTDIST}/gcc/config/aarch64/aarch64.h ${GNUHOSTDIST}/gcc/config/dbxelf.h ${GNUHOSTDIST}/gcc/config/elfos.h ${GNUHOSTDIST}/gcc/config/netbsd.h ${GNUHOSTDIST}/gcc/config/netbsd-stdint.h ${GNUHOSTDIST}/gcc/config/netbsd-elf.h ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-elf.h ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-errata.h ${GNUHOSTDIST}/gcc/config/aarch64/aarch64-netbsd.h ${GNUHOSTDIST}/gcc/config/initfini-array.h ${GNUHOSTDIST}/gcc/defaults.h
G_build_xm_include_list=auto-build.h ansidecl.h
G_lang_specs_files=${GNUHOSTDIST}/gcc/cp/lang-specs.h ${GNUHOSTDIST}/gcc/fortran/lang-specs.h ${GNUHOSTDIST}/gcc/lto/lang-specs.h ${GNUHOSTDIST}/gcc/objc/lang-specs.h
G_tm_p_include_list=config/aarch64/aarch64-protos.h config/arm/aarch-common-protos.h config/netbsd-protos.h tm-preds.h
G_common_out_file=${GNUHOSTDIST}/gcc/common/config/aarch64/aarch64-common.cc
G_LIB2ADDEHDEP=
G_CXX_OBJS=cp-lang.o c-family/stub-objc.o call.o class.o constexpr.o constraint.o coroutines.o cp-gimplify.o cp-objcp-common.o cp-ubsan.o cvt.o cxx-pretty-print.o decl.o decl2.o dump.o error.o except.o expr.o friend.o init.o lambda.o lex.o logic.o mangle.o mapper-client.o mapper-resolver.o method.o module.o name-lookup.o optimize.o parser.o pt.o ptree.o rtti.o search.o semantics.o tree.o typeck.o typeck2.o vtable-class-hierarchy.o attribs.o incpath.o c-family/c-common.o c-family/c-cppbuiltin.o c-family/c-dump.o c-family/c-format.o c-family/c-gimplify.o c-family/c-indentation.o c-family/c-lex.o c-family/c-omp.o c-family/c-opts.o c-family/c-pch.o c-family/c-ppoutput.o c-family/c-pragma.o c-family/c-pretty-print.o c-family/c-semantics.o c-family/c-ada-spec.o c-family/c-ubsan.o c-family/known-headers.o c-family/c-attribs.o c-family/c-warn.o c-family/c-spellcheck.o aarch64-c.o default-c.o
G_CXX_C_OBJS=attribs.o incpath.o c-family/c-common.o c-family/c-cppbuiltin.o c-family/c-dump.o c-family/c-format.o c-family/c-gimplify.o c-family/c-indentation.o c-family/c-lex.o c-family/c-omp.o c-family/c-opts.o c-family/c-pch.o c-family/c-ppoutput.o c-family/c-pragma.o c-family/c-pretty-print.o c-family/c-semantics.o c-family/c-ada-spec.o c-family/c-ubsan.o c-family/known-headers.o c-family/c-attribs.o c-family/c-warn.o c-family/c-spellcheck.o aarch64-c.o default-c.o
G_F77_OBJS=
G_libcpp_a_OBJS=charset.o directives.o errors.o expr.o files.o identifiers.o init.o lex.o line-map.o macro.o mkdeps.o pch.o symtab.o traditional.o
G_ENABLE_SHARED=yes
G_SHLIB_LINK= -shared
G_SHLIB_MULTILIB=.
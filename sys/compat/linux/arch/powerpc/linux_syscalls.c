/* $NetBSD: linux_syscalls.c,v 1.97 2024/07/01 01:36:19 christos Exp $ */

/*
 * System call names.
 *
 * DO NOT EDIT-- this file is automatically generated.
 * created from	NetBSD: syscalls.master,v 1.86 2024/07/01 01:35:53 christos Exp  
 */

#include <sys/cdefs.h>
__KERNEL_RCSID(0, "$NetBSD: linux_syscalls.c,v 1.97 2024/07/01 01:36:19 christos Exp $");

#if defined(_KERNEL_OPT)
#include <sys/param.h>
#include <sys/poll.h>
#include <sys/systm.h>
#include <sys/signal.h>
#include <sys/mount.h>
#include <sys/syscallargs.h>
#include <compat/linux/common/linux_types.h>
#include <compat/linux/common/linux_signal.h>
#include <compat/linux/common/linux_siginfo.h>
#include <compat/linux/common/linux_machdep.h>
#include <compat/linux/common/linux_mmap.h>
#include <compat/linux/common/linux_mqueue.h>
#include <compat/linux/common/linux_sched.h>
#include <compat/linux/linux_syscallargs.h>
#else /* _KERNEL_OPT */
#include <sys/null.h>
#endif /* _KERNEL_OPT */

const char *const linux_syscallnames[] = {
	/*   0 */	"syscall",
	/*   1 */	"exit",
	/*   2 */	"fork",
	/*   3 */	"read",
	/*   4 */	"write",
	/*   5 */	"open",
	/*   6 */	"close",
	/*   7 */	"waitpid",
	/*   8 */	"creat",
	/*   9 */	"link",
	/*  10 */	"unlink",
	/*  11 */	"execve",
	/*  12 */	"chdir",
	/*  13 */	"time",
	/*  14 */	"mknod",
	/*  15 */	"chmod",
	/*  16 */	"__posix_lchown",
	/*  17 */	"#17 (obsolete break)",
	/*  18 */	"#18 (obsolete ostat)",
	/*  19 */	"lseek",
	/*  20 */	"getpid",
	/*  21 */	"#21 (unimplemented mount)",
	/*  22 */	"#22 (obsolete umount)",
	/*  23 */	"setuid",
	/*  24 */	"getuid",
	/*  25 */	"stime",
	/*  26 */	"ptrace",
	/*  27 */	"alarm",
	/*  28 */	"#28 (obsolete ofstat)",
	/*  29 */	"pause",
	/*  30 */	"utime",
	/*  31 */	"#31 (obsolete stty)",
	/*  32 */	"#32 (obsolete gtty)",
	/*  33 */	"access",
	/*  34 */	"nice",
	/*  35 */	"#35 (obsolete ftime)",
	/*  36 */	"sync",
	/*  37 */	"kill",
	/*  38 */	"__posix_rename",
	/*  39 */	"mkdir",
	/*  40 */	"rmdir",
	/*  41 */	"dup",
	/*  42 */	"pipe",
	/*  43 */	"times",
	/*  44 */	"#44 (obsolete prof)",
	/*  45 */	"brk",
	/*  46 */	"setgid",
	/*  47 */	"getgid",
	/*  48 */	"signal",
	/*  49 */	"geteuid",
	/*  50 */	"getegid",
	/*  51 */	"acct",
	/*  52 */	"#52 (unimplemented umount)",
	/*  53 */	"#53 (obsolete lock)",
	/*  54 */	"ioctl",
	/*  55 */	"fcntl",
	/*  56 */	"#56 (obsolete mpx)",
	/*  57 */	"setpgid",
	/*  58 */	"#58 (obsolete ulimit)",
	/*  59 */	"olduname",
	/*  60 */	"umask",
	/*  61 */	"chroot",
	/*  62 */	"#62 (unimplemented ustat)",
	/*  63 */	"dup2",
	/*  64 */	"getppid",
	/*  65 */	"getpgrp",
	/*  66 */	"setsid",
	/*  67 */	"sigaction",
	/*  68 */	"siggetmask",
	/*  69 */	"sigsetmask",
	/*  70 */	"setreuid",
	/*  71 */	"setregid",
	/*  72 */	"sigsuspend",
	/*  73 */	"sigpending",
	/*  74 */	"sethostname",
	/*  75 */	"setrlimit",
	/*  76 */	"getrlimit",
	/*  77 */	"getrusage",
	/*  78 */	"gettimeofday",
	/*  79 */	"settimeofday",
	/*  80 */	"getgroups",
	/*  81 */	"setgroups",
	/*  82 */	"select",
	/*  83 */	"symlink",
	/*  84 */	"oolstat",
	/*  85 */	"readlink",
#ifdef EXEC_AOUT
	/*  86 */	"uselib",
#else
	/*  86 */	"#86 (unimplemented sys_uselib)",
#endif
	/*  87 */	"swapon",
	/*  88 */	"reboot",
	/*  89 */	"readdir",
	/*  90 */	"mmap",
	/*  91 */	"munmap",
	/*  92 */	"truncate",
	/*  93 */	"ftruncate",
	/*  94 */	"fchmod",
	/*  95 */	"__posix_fchown",
	/*  96 */	"getpriority",
	/*  97 */	"setpriority",
	/*  98 */	"profil",
	/*  99 */	"statfs",
	/* 100 */	"fstatfs",
	/* 101 */	"#101 (unimplemented ioperm)",
	/* 102 */	"socketcall",
	/* 103 */	"#103 (unimplemented syslog)",
	/* 104 */	"setitimer",
	/* 105 */	"getitimer",
	/* 106 */	"stat",
	/* 107 */	"lstat",
	/* 108 */	"fstat",
	/* 109 */	"uname",
	/* 110 */	"#110 (unimplemented iopl)",
	/* 111 */	"#111 (unimplemented vhangup)",
	/* 112 */	"#112 (unimplemented idle)",
	/* 113 */	"#113 (unimplemented vm86old)",
	/* 114 */	"wait4",
	/* 115 */	"swapoff",
	/* 116 */	"sysinfo",
	/* 117 */	"ipc",
	/* 118 */	"fsync",
	/* 119 */	"sigreturn",
	/* 120 */	"clone",
	/* 121 */	"setdomainname",
	/* 122 */	"new_uname",
	/* 123 */	"#123 (unimplemented modify_ldt)",
	/* 124 */	"#124 (unimplemented adjtimex)",
	/* 125 */	"mprotect",
	/* 126 */	"sigprocmask",
	/* 127 */	"#127 (unimplemented create_module)",
	/* 128 */	"#128 (unimplemented init_module)",
	/* 129 */	"#129 (unimplemented delete_module)",
	/* 130 */	"#130 (unimplemented get_kernel_syms)",
	/* 131 */	"#131 (unimplemented quotactl)",
	/* 132 */	"getpgid",
	/* 133 */	"fchdir",
	/* 134 */	"#134 (unimplemented bdflush)",
	/* 135 */	"#135 (unimplemented sysfs)",
	/* 136 */	"personality",
	/* 137 */	"#137 (unimplemented afs_syscall)",
	/* 138 */	"setfsuid",
	/* 139 */	"setfsgid",
	/* 140 */	"llseek",
	/* 141 */	"getdents",
	/* 142 */	"new_select",
	/* 143 */	"flock",
	/* 144 */	"__msync13",
	/* 145 */	"readv",
	/* 146 */	"writev",
	/* 147 */	"getsid",
	/* 148 */	"fdatasync",
	/* 149 */	"__sysctl",
	/* 150 */	"mlock",
	/* 151 */	"munlock",
	/* 152 */	"mlockall",
	/* 153 */	"munlockall",
	/* 154 */	"sched_setparam",
	/* 155 */	"sched_getparam",
	/* 156 */	"sched_setscheduler",
	/* 157 */	"sched_getscheduler",
	/* 158 */	"sched_yield",
	/* 159 */	"sched_get_priority_max",
	/* 160 */	"sched_get_priority_min",
	/* 161 */	"#161 (unimplemented sched_rr_get_interval)",
	/* 162 */	"nanosleep",
	/* 163 */	"mremap",
	/* 164 */	"setresuid",
	/* 165 */	"getresuid",
	/* 166 */	"#166 (unimplemented query_module)",
	/* 167 */	"poll",
	/* 168 */	"#168 (unimplemented nfsservctl)",
	/* 169 */	"setresgid",
	/* 170 */	"getresgid",
	/* 171 */	"#171 (unimplemented prctl)",
	/* 172 */	"rt_sigreturn",
	/* 173 */	"rt_sigaction",
	/* 174 */	"rt_sigprocmask",
	/* 175 */	"rt_sigpending",
	/* 176 */	"rt_sigtimedwait",
	/* 177 */	"rt_queueinfo",
	/* 178 */	"rt_sigsuspend",
	/* 179 */	"pread",
	/* 180 */	"pwrite",
	/* 181 */	"__posix_chown",
	/* 182 */	"__getcwd",
	/* 183 */	"#183 (unimplemented capget)",
	/* 184 */	"#184 (unimplemented capset)",
	/* 185 */	"sigaltstack",
	/* 186 */	"#186 (unimplemented sendfile)",
	/* 187 */	"#187 (unimplemented getpmsg)",
	/* 188 */	"#188 (unimplemented putpmsg)",
	/* 189 */	"__vfork14",
	/* 190 */	"ugetrlimit",
	/* 191 */	"readahead",
#define linux_sys_mmap2_args linux_sys_mmap_args
	/* 192 */	"mmap2",
	/* 193 */	"truncate64",
	/* 194 */	"ftruncate64",
	/* 195 */	"stat64",
	/* 196 */	"lstat64",
	/* 197 */	"fstat64",
	/* 198 */	"#198 (unimplemented sys_pciconfig_read)",
	/* 199 */	"#199 (unimplemented sys_pciconfig_write)",
	/* 200 */	"#200 (unimplemented sys_pciconfig_iobase)",
	/* 201 */	"#201 (unimplemented / * Unused ( MacOnLinux project ) * /)",
	/* 202 */	"getdents64",
	/* 203 */	"#203 (unimplemented pivot_root)",
	/* 204 */	"fcntl64",
	/* 205 */	"mincore",
	/* 206 */	"madvise",
	/* 207 */	"gettid",
	/* 208 */	"tkill",
	/* 209 */	"setxattr",
	/* 210 */	"lsetxattr",
	/* 211 */	"fsetxattr",
	/* 212 */	"getxattr",
	/* 213 */	"lgetxattr",
	/* 214 */	"fgetxattr",
	/* 215 */	"listxattr",
	/* 216 */	"llistxattr",
	/* 217 */	"flistxattr",
	/* 218 */	"removexattr",
	/* 219 */	"lremovexattr",
	/* 220 */	"fremovexattr",
	/* 221 */	"futex",
	/* 222 */	"sched_setaffinity",
	/* 223 */	"sched_getaffinity",
	/* 224 */	"#224 (unimplemented / * unused * /)",
	/* 225 */	"#225 (unimplemented tuxcall)",
	/* 226 */	"#226 (unimplemented sendfile64)",
	/* 227 */	"#227 (unimplemented io_setup)",
	/* 228 */	"#228 (unimplemented io_destroy)",
	/* 229 */	"#229 (unimplemented io_getevents)",
	/* 230 */	"#230 (unimplemented io_submit)",
	/* 231 */	"#231 (unimplemented io_cancel)",
	/* 232 */	"set_tid_address",
	/* 233 */	"fadvise64",
	/* 234 */	"exit_group",
	/* 235 */	"#235 (unimplemented lookup_dcookie)",
	/* 236 */	"epoll_create",
	/* 237 */	"epoll_ctl",
	/* 238 */	"epoll_wait",
	/* 239 */	"#239 (unimplemented remap_file_pages)",
	/* 240 */	"timer_create",
	/* 241 */	"timer_settime",
	/* 242 */	"timer_gettime",
	/* 243 */	"timer_getoverrun",
	/* 244 */	"timer_delete",
	/* 245 */	"clock_settime",
	/* 246 */	"clock_gettime",
	/* 247 */	"clock_getres",
	/* 248 */	"clock_nanosleep",
	/* 249 */	"#249 (unimplemented swapcontext)",
	/* 250 */	"tgkill",
	/* 251 */	"utimes",
	/* 252 */	"statfs64",
	/* 253 */	"fstatfs64",
	/* 254 */	"fadvise64_64",
	/* 255 */	"#255 (unimplemented rtas)",
	/* 256 */	"#256 (unimplemented / * reserved for sys_debug_setcontext * /)",
	/* 257 */	"#257 (unimplemented / * reserved for vserver * /)",
	/* 258 */	"#258 (unimplemented / * reserved for new sys_remap_file_pages * /)",
	/* 259 */	"#259 (unimplemented / * reserved for new sys_mbind * /)",
	/* 260 */	"#260 (unimplemented / * reserved for new sys_get_mempolicy * /)",
	/* 261 */	"#261 (unimplemented / * reserved for new sys_set_mempolicy * /)",
	/* 262 */	"mq_open",
	/* 263 */	"mq_unlink",
	/* 264 */	"mq_timedsend",
	/* 265 */	"mq_timedreceive",
	/* 266 */	"mq_notify",
	/* 267 */	"mq_getsetattr",
	/* 268 */	"#268 (unimplemented kexec_load)",
	/* 269 */	"#269 (unimplemented add_key)",
	/* 270 */	"#270 (unimplemented request_key)",
	/* 271 */	"#271 (unimplemented keyctl)",
	/* 272 */	"waitid",
	/* 273 */	"#273 (unimplemented ioprio_set)",
	/* 274 */	"#274 (unimplemented ioprio_get)",
	/* 275 */	"inotify_init",
	/* 276 */	"inotify_add_watch",
	/* 277 */	"inotify_rm_watch",
	/* 278 */	"#278 (unimplemented spu_run)",
	/* 279 */	"#279 (unimplemented spu_create)",
	/* 280 */	"pselect6",
	/* 281 */	"ppoll",
	/* 282 */	"#282 (unimplemented unshare)",
	/* 283 */	"#283 (unimplemented splice)",
	/* 284 */	"#284 (unimplemented tee)",
	/* 285 */	"#285 (unimplemented vmsplice)",
	/* 286 */	"openat",
	/* 287 */	"mkdirat",
	/* 288 */	"mknodat",
	/* 289 */	"fchownat",
	/* 290 */	"#290 (unimplemented futimesat)",
	/* 291 */	"fstatat64",
	/* 292 */	"unlinkat",
	/* 293 */	"renameat",
	/* 294 */	"linkat",
	/* 295 */	"symlinkat",
	/* 296 */	"readlinkat",
	/* 297 */	"fchmodat",
	/* 298 */	"faccessat",
	/* 299 */	"__futex_set_robust_list",
	/* 300 */	"__futex_get_robust_list",
	/* 301 */	"#301 (unimplemented move_pages)",
	/* 302 */	"getcpu",
	/* 303 */	"epoll_pwait",
	/* 304 */	"utimensat",
	/* 305 */	"#305 (unimplemented signalfd)",
	/* 306 */	"timerfd_create",
	/* 307 */	"eventfd",
	/* 308 */	"#308 (unimplemented sync_file_range2)",
	/* 309 */	"fallocate",
	/* 310 */	"#310 (unimplemented subpage_prot)",
	/* 311 */	"timerfd_settime",
	/* 312 */	"timerfd_gettime",
	/* 313 */	"#313 (unimplemented signalfd4)",
	/* 314 */	"eventfd2",
	/* 315 */	"epoll_create1",
	/* 316 */	"dup3",
	/* 317 */	"pipe2",
	/* 318 */	"inotify_init1",
	/* 319 */	"#319 (unimplemented perf_event_open)",
	/* 320 */	"preadv",
	/* 321 */	"pwritev",
	/* 322 */	"#322 (unimplemented rt_tgsigqueueinfo)",
	/* 323 */	"#323 (unimplemented fanotify_init)",
	/* 324 */	"#324 (unimplemented fanotify_mark)",
	/* 325 */	"prlimit64",
	/* 326 */	"#326 (unimplemented socket)",
	/* 327 */	"#327 (unimplemented bind)",
	/* 328 */	"#328 (unimplemented connect)",
	/* 329 */	"#329 (unimplemented listen)",
	/* 330 */	"#330 (unimplemented accept)",
	/* 331 */	"#331 (unimplemented getsockname)",
	/* 332 */	"#332 (unimplemented getpeername)",
	/* 333 */	"#333 (unimplemented socketpair)",
	/* 334 */	"#334 (unimplemented send)",
	/* 335 */	"#335 (unimplemented sendto)",
	/* 336 */	"#336 (unimplemented recv)",
	/* 337 */	"#337 (unimplemented recvfrom)",
	/* 338 */	"#338 (unimplemented shutdown)",
	/* 339 */	"#339 (unimplemented setsockopt)",
	/* 340 */	"#340 (unimplemented getsockopt)",
	/* 341 */	"#341 (unimplemented sendmsg)",
	/* 342 */	"#342 (unimplemented recvmsg)",
	/* 343 */	"recvmmsg",
	/* 344 */	"accept4",
	/* 345 */	"#345 (unimplemented name_to_handle_at)",
	/* 346 */	"#346 (unimplemented open_by_handle_at)",
	/* 347 */	"#347 (unimplemented clock_adjtime)",
	/* 348 */	"#348 (unimplemented syncfs)",
	/* 349 */	"sendmmsg",
	/* 350 */	"#350 (unimplemented setns)",
	/* 351 */	"#351 (unimplemented process_vm_readv)",
	/* 352 */	"#352 (unimplemented process_vm_writev)",
	/* 353 */	"#353 (unimplemented finit_module)",
	/* 354 */	"#354 (unimplemented kcmp)",
	/* 355 */	"#355 (unimplemented sched_setattr)",
	/* 356 */	"#356 (unimplemented sched_getattr)",
	/* 357 */	"#357 (unimplemented renameat2)",
	/* 358 */	"#358 (unimplemented seccomp)",
	/* 359 */	"getrandom",
	/* 360 */	"#360 (unimplemented memfd_create)",
	/* 361 */	"#361 (unimplemented bpf)",
	/* 362 */	"#362 (unimplemented execveat)",
	/* 363 */	"#363 (unimplemented switch_endian)",
	/* 364 */	"#364 (unimplemented userfaultfd)",
	/* 365 */	"#365 (unimplemented membarrier)",
	/* 366 */	"#366 (unimplemented)",
	/* 367 */	"#367 (unimplemented)",
	/* 368 */	"#368 (unimplemented)",
	/* 369 */	"#369 (unimplemented)",
	/* 370 */	"#370 (unimplemented)",
	/* 371 */	"#371 (unimplemented)",
	/* 372 */	"#372 (unimplemented)",
	/* 373 */	"#373 (unimplemented)",
	/* 374 */	"#374 (unimplemented)",
	/* 375 */	"#375 (unimplemented)",
	/* 376 */	"#376 (unimplemented)",
	/* 377 */	"#377 (unimplemented)",
	/* 378 */	"#378 (unimplemented mlock2)",
	/* 379 */	"#379 (unimplemented copy_file_range)",
	/* 380 */	"#380 (unimplemented preadv2)",
	/* 381 */	"#381 (unimplemented pwritev2)",
	/* 382 */	"#382 (unimplemented kexec_file_load)",
	/* 383 */	"statx",
	/* 384 */	"#384 (unimplemented)",
	/* 385 */	"#385 (unimplemented)",
	/* 386 */	"#386 (unimplemented)",
	/* 387 */	"#387 (unimplemented)",
	/* 388 */	"#388 (unimplemented)",
	/* 389 */	"#389 (unimplemented)",
	/* 390 */	"#390 (unimplemented)",
	/* 391 */	"#391 (unimplemented)",
	/* 392 */	"#392 (unimplemented)",
	/* 393 */	"#393 (unimplemented)",
	/* 394 */	"#394 (unimplemented)",
	/* 395 */	"#395 (unimplemented)",
	/* 396 */	"#396 (unimplemented)",
	/* 397 */	"#397 (unimplemented)",
	/* 398 */	"#398 (unimplemented)",
	/* 399 */	"#399 (unimplemented)",
	/* 400 */	"#400 (unimplemented)",
	/* 401 */	"#401 (unimplemented)",
	/* 402 */	"#402 (unimplemented)",
	/* 403 */	"#403 (unimplemented)",
	/* 404 */	"#404 (unimplemented)",
	/* 405 */	"#405 (unimplemented)",
	/* 406 */	"#406 (unimplemented)",
	/* 407 */	"#407 (unimplemented)",
	/* 408 */	"#408 (unimplemented)",
	/* 409 */	"#409 (unimplemented)",
	/* 410 */	"#410 (unimplemented)",
	/* 411 */	"#411 (unimplemented)",
	/* 412 */	"#412 (unimplemented)",
	/* 413 */	"#413 (unimplemented)",
	/* 414 */	"#414 (unimplemented)",
	/* 415 */	"#415 (unimplemented)",
	/* 416 */	"#416 (unimplemented)",
	/* 417 */	"#417 (unimplemented)",
	/* 418 */	"#418 (unimplemented)",
	/* 419 */	"#419 (unimplemented)",
	/* 420 */	"#420 (unimplemented)",
	/* 421 */	"#421 (unimplemented)",
	/* 422 */	"#422 (unimplemented)",
	/* 423 */	"#423 (unimplemented)",
	/* 424 */	"#424 (unimplemented)",
	/* 425 */	"#425 (unimplemented)",
	/* 426 */	"#426 (unimplemented)",
	/* 427 */	"#427 (unimplemented)",
	/* 428 */	"#428 (unimplemented)",
	/* 429 */	"#429 (unimplemented)",
	/* 430 */	"#430 (unimplemented)",
	/* 431 */	"#431 (unimplemented)",
	/* 432 */	"#432 (unimplemented)",
	/* 433 */	"#433 (unimplemented)",
	/* 434 */	"#434 (unimplemented)",
	/* 435 */	"#435 (unimplemented)",
	/* 436 */	"close_range",
	/* 437 */	"#437 (unimplemented)",
	/* 438 */	"#438 (unimplemented)",
	/* 439 */	"faccessat2",
	/* 440 */	"#440 (unimplemented)",
	/* 441 */	"epoll_pwait2",
	/* 442 */	"# filler",
	/* 443 */	"# filler",
	/* 444 */	"# filler",
	/* 445 */	"# filler",
	/* 446 */	"# filler",
	/* 447 */	"# filler",
	/* 448 */	"# filler",
	/* 449 */	"# filler",
	/* 450 */	"# filler",
	/* 451 */	"# filler",
	/* 452 */	"# filler",
	/* 453 */	"# filler",
	/* 454 */	"# filler",
	/* 455 */	"# filler",
	/* 456 */	"# filler",
	/* 457 */	"# filler",
	/* 458 */	"# filler",
	/* 459 */	"# filler",
	/* 460 */	"# filler",
	/* 461 */	"# filler",
	/* 462 */	"# filler",
	/* 463 */	"# filler",
	/* 464 */	"# filler",
	/* 465 */	"# filler",
	/* 466 */	"# filler",
	/* 467 */	"# filler",
	/* 468 */	"# filler",
	/* 469 */	"# filler",
	/* 470 */	"# filler",
	/* 471 */	"# filler",
	/* 472 */	"# filler",
	/* 473 */	"# filler",
	/* 474 */	"# filler",
	/* 475 */	"# filler",
	/* 476 */	"# filler",
	/* 477 */	"# filler",
	/* 478 */	"# filler",
	/* 479 */	"# filler",
	/* 480 */	"# filler",
	/* 481 */	"# filler",
	/* 482 */	"# filler",
	/* 483 */	"# filler",
	/* 484 */	"# filler",
	/* 485 */	"# filler",
	/* 486 */	"# filler",
	/* 487 */	"# filler",
	/* 488 */	"# filler",
	/* 489 */	"# filler",
	/* 490 */	"# filler",
	/* 491 */	"# filler",
	/* 492 */	"# filler",
	/* 493 */	"# filler",
	/* 494 */	"# filler",
	/* 495 */	"# filler",
	/* 496 */	"# filler",
	/* 497 */	"# filler",
	/* 498 */	"# filler",
	/* 499 */	"# filler",
	/* 500 */	"# filler",
	/* 501 */	"# filler",
	/* 502 */	"# filler",
	/* 503 */	"# filler",
	/* 504 */	"# filler",
	/* 505 */	"# filler",
	/* 506 */	"# filler",
	/* 507 */	"# filler",
	/* 508 */	"# filler",
	/* 509 */	"# filler",
	/* 510 */	"# filler",
	/* 511 */	"# filler",
};


/* libc style syscall names */
const char *const altlinux_syscallnames[] = {
	/*   0 */	"nosys",
	/*   1 */	NULL, /* exit */
	/*   2 */	NULL, /* fork */
	/*   3 */	NULL, /* read */
	/*   4 */	NULL, /* write */
	/*   5 */	NULL, /* open */
	/*   6 */	NULL, /* close */
	/*   7 */	NULL, /* waitpid */
	/*   8 */	NULL, /* creat */
	/*   9 */	NULL, /* link */
	/*  10 */	NULL, /* unlink */
	/*  11 */	NULL, /* execve */
	/*  12 */	NULL, /* chdir */
	/*  13 */	NULL, /* time */
	/*  14 */	NULL, /* mknod */
	/*  15 */	NULL, /* chmod */
	/*  16 */	NULL, /* __posix_lchown */
	/*  17 */	NULL, /* obsolete break */
	/*  18 */	NULL, /* obsolete ostat */
	/*  19 */	NULL, /* lseek */
	/*  20 */	NULL, /* getpid */
	/*  21 */	NULL, /* unimplemented mount */
	/*  22 */	NULL, /* obsolete umount */
	/*  23 */	NULL, /* setuid */
	/*  24 */	NULL, /* getuid */
	/*  25 */	NULL, /* stime */
	/*  26 */	NULL, /* ptrace */
	/*  27 */	NULL, /* alarm */
	/*  28 */	NULL, /* obsolete ofstat */
	/*  29 */	NULL, /* pause */
	/*  30 */	NULL, /* utime */
	/*  31 */	NULL, /* obsolete stty */
	/*  32 */	NULL, /* obsolete gtty */
	/*  33 */	NULL, /* access */
	/*  34 */	NULL, /* nice */
	/*  35 */	NULL, /* obsolete ftime */
	/*  36 */	NULL, /* sync */
	/*  37 */	NULL, /* kill */
	/*  38 */	NULL, /* __posix_rename */
	/*  39 */	NULL, /* mkdir */
	/*  40 */	NULL, /* rmdir */
	/*  41 */	NULL, /* dup */
	/*  42 */	NULL, /* pipe */
	/*  43 */	NULL, /* times */
	/*  44 */	NULL, /* obsolete prof */
	/*  45 */	NULL, /* brk */
	/*  46 */	NULL, /* setgid */
	/*  47 */	NULL, /* getgid */
	/*  48 */	NULL, /* signal */
	/*  49 */	NULL, /* geteuid */
	/*  50 */	NULL, /* getegid */
	/*  51 */	NULL, /* acct */
	/*  52 */	NULL, /* unimplemented umount */
	/*  53 */	NULL, /* obsolete lock */
	/*  54 */	NULL, /* ioctl */
	/*  55 */	NULL, /* fcntl */
	/*  56 */	NULL, /* obsolete mpx */
	/*  57 */	NULL, /* setpgid */
	/*  58 */	NULL, /* obsolete ulimit */
	/*  59 */	NULL, /* olduname */
	/*  60 */	NULL, /* umask */
	/*  61 */	NULL, /* chroot */
	/*  62 */	NULL, /* unimplemented ustat */
	/*  63 */	NULL, /* dup2 */
	/*  64 */	NULL, /* getppid */
	/*  65 */	NULL, /* getpgrp */
	/*  66 */	NULL, /* setsid */
	/*  67 */	NULL, /* sigaction */
	/*  68 */	NULL, /* siggetmask */
	/*  69 */	NULL, /* sigsetmask */
	/*  70 */	NULL, /* setreuid */
	/*  71 */	NULL, /* setregid */
	/*  72 */	NULL, /* sigsuspend */
	/*  73 */	NULL, /* sigpending */
	/*  74 */	NULL, /* sethostname */
	/*  75 */	NULL, /* setrlimit */
	/*  76 */	NULL, /* getrlimit */
	/*  77 */	NULL, /* getrusage */
	/*  78 */	NULL, /* gettimeofday */
	/*  79 */	NULL, /* settimeofday */
	/*  80 */	NULL, /* getgroups */
	/*  81 */	NULL, /* setgroups */
	/*  82 */	NULL, /* select */
	/*  83 */	NULL, /* symlink */
	/*  84 */	"lstat",
	/*  85 */	NULL, /* readlink */
#ifdef EXEC_AOUT
	/*  86 */	NULL, /* uselib */
#else
	/*  86 */	NULL, /* unimplemented sys_uselib */
#endif
	/*  87 */	NULL, /* swapon */
	/*  88 */	NULL, /* reboot */
	/*  89 */	NULL, /* readdir */
	/*  90 */	NULL, /* mmap */
	/*  91 */	NULL, /* munmap */
	/*  92 */	NULL, /* truncate */
	/*  93 */	NULL, /* ftruncate */
	/*  94 */	NULL, /* fchmod */
	/*  95 */	NULL, /* __posix_fchown */
	/*  96 */	NULL, /* getpriority */
	/*  97 */	NULL, /* setpriority */
	/*  98 */	NULL, /* profil */
	/*  99 */	NULL, /* statfs */
	/* 100 */	NULL, /* fstatfs */
	/* 101 */	NULL, /* unimplemented ioperm */
	/* 102 */	NULL, /* socketcall */
	/* 103 */	NULL, /* unimplemented syslog */
	/* 104 */	NULL, /* setitimer */
	/* 105 */	NULL, /* getitimer */
	/* 106 */	NULL, /* stat */
	/* 107 */	NULL, /* lstat */
	/* 108 */	NULL, /* fstat */
	/* 109 */	NULL, /* uname */
	/* 110 */	NULL, /* unimplemented iopl */
	/* 111 */	NULL, /* unimplemented vhangup */
	/* 112 */	NULL, /* unimplemented idle */
	/* 113 */	NULL, /* unimplemented vm86old */
	/* 114 */	NULL, /* wait4 */
	/* 115 */	NULL, /* swapoff */
	/* 116 */	NULL, /* sysinfo */
	/* 117 */	NULL, /* ipc */
	/* 118 */	NULL, /* fsync */
	/* 119 */	NULL, /* sigreturn */
	/* 120 */	NULL, /* clone */
	/* 121 */	NULL, /* setdomainname */
	/* 122 */	NULL, /* new_uname */
	/* 123 */	NULL, /* unimplemented modify_ldt */
	/* 124 */	NULL, /* unimplemented adjtimex */
	/* 125 */	NULL, /* mprotect */
	/* 126 */	NULL, /* sigprocmask */
	/* 127 */	NULL, /* unimplemented create_module */
	/* 128 */	NULL, /* unimplemented init_module */
	/* 129 */	NULL, /* unimplemented delete_module */
	/* 130 */	NULL, /* unimplemented get_kernel_syms */
	/* 131 */	NULL, /* unimplemented quotactl */
	/* 132 */	NULL, /* getpgid */
	/* 133 */	NULL, /* fchdir */
	/* 134 */	NULL, /* unimplemented bdflush */
	/* 135 */	NULL, /* unimplemented sysfs */
	/* 136 */	NULL, /* personality */
	/* 137 */	NULL, /* unimplemented afs_syscall */
	/* 138 */	NULL, /* setfsuid */
	/* 139 */	NULL, /* setfsgid */
	/* 140 */	NULL, /* llseek */
	/* 141 */	NULL, /* getdents */
	/* 142 */	NULL, /* new_select */
	/* 143 */	NULL, /* flock */
	/* 144 */	"msync",
	/* 145 */	NULL, /* readv */
	/* 146 */	NULL, /* writev */
	/* 147 */	NULL, /* getsid */
	/* 148 */	NULL, /* fdatasync */
	/* 149 */	NULL, /* __sysctl */
	/* 150 */	NULL, /* mlock */
	/* 151 */	NULL, /* munlock */
	/* 152 */	NULL, /* mlockall */
	/* 153 */	NULL, /* munlockall */
	/* 154 */	NULL, /* sched_setparam */
	/* 155 */	NULL, /* sched_getparam */
	/* 156 */	NULL, /* sched_setscheduler */
	/* 157 */	NULL, /* sched_getscheduler */
	/* 158 */	NULL, /* sched_yield */
	/* 159 */	NULL, /* sched_get_priority_max */
	/* 160 */	NULL, /* sched_get_priority_min */
	/* 161 */	NULL, /* unimplemented sched_rr_get_interval */
	/* 162 */	NULL, /* nanosleep */
	/* 163 */	NULL, /* mremap */
	/* 164 */	NULL, /* setresuid */
	/* 165 */	NULL, /* getresuid */
	/* 166 */	NULL, /* unimplemented query_module */
	/* 167 */	NULL, /* poll */
	/* 168 */	NULL, /* unimplemented nfsservctl */
	/* 169 */	NULL, /* setresgid */
	/* 170 */	NULL, /* getresgid */
	/* 171 */	NULL, /* unimplemented prctl */
	/* 172 */	NULL, /* rt_sigreturn */
	/* 173 */	NULL, /* rt_sigaction */
	/* 174 */	NULL, /* rt_sigprocmask */
	/* 175 */	NULL, /* rt_sigpending */
	/* 176 */	NULL, /* rt_sigtimedwait */
	/* 177 */	NULL, /* rt_queueinfo */
	/* 178 */	NULL, /* rt_sigsuspend */
	/* 179 */	NULL, /* pread */
	/* 180 */	NULL, /* pwrite */
	/* 181 */	NULL, /* __posix_chown */
	/* 182 */	NULL, /* __getcwd */
	/* 183 */	NULL, /* unimplemented capget */
	/* 184 */	NULL, /* unimplemented capset */
	/* 185 */	NULL, /* sigaltstack */
	/* 186 */	NULL, /* unimplemented sendfile */
	/* 187 */	NULL, /* unimplemented getpmsg */
	/* 188 */	NULL, /* unimplemented putpmsg */
	/* 189 */	"vfork",
	/* 190 */	NULL, /* ugetrlimit */
	/* 191 */	NULL, /* readahead */
#define linux_sys_mmap2_args linux_sys_mmap_args
	/* 192 */	NULL, /* mmap2 */
	/* 193 */	NULL, /* truncate64 */
	/* 194 */	NULL, /* ftruncate64 */
	/* 195 */	NULL, /* stat64 */
	/* 196 */	NULL, /* lstat64 */
	/* 197 */	NULL, /* fstat64 */
	/* 198 */	NULL, /* unimplemented sys_pciconfig_read */
	/* 199 */	NULL, /* unimplemented sys_pciconfig_write */
	/* 200 */	NULL, /* unimplemented sys_pciconfig_iobase */
	/* 201 */	NULL, /* unimplemented / * Unused ( MacOnLinux project ) * / */
	/* 202 */	NULL, /* getdents64 */
	/* 203 */	NULL, /* unimplemented pivot_root */
	/* 204 */	NULL, /* fcntl64 */
	/* 205 */	NULL, /* mincore */
	/* 206 */	NULL, /* madvise */
	/* 207 */	NULL, /* gettid */
	/* 208 */	NULL, /* tkill */
	/* 209 */	NULL, /* setxattr */
	/* 210 */	NULL, /* lsetxattr */
	/* 211 */	NULL, /* fsetxattr */
	/* 212 */	NULL, /* getxattr */
	/* 213 */	NULL, /* lgetxattr */
	/* 214 */	NULL, /* fgetxattr */
	/* 215 */	NULL, /* listxattr */
	/* 216 */	NULL, /* llistxattr */
	/* 217 */	NULL, /* flistxattr */
	/* 218 */	NULL, /* removexattr */
	/* 219 */	NULL, /* lremovexattr */
	/* 220 */	NULL, /* fremovexattr */
	/* 221 */	NULL, /* futex */
	/* 222 */	NULL, /* sched_setaffinity */
	/* 223 */	NULL, /* sched_getaffinity */
	/* 224 */	NULL, /* unimplemented / * unused * / */
	/* 225 */	NULL, /* unimplemented tuxcall */
	/* 226 */	NULL, /* unimplemented sendfile64 */
	/* 227 */	NULL, /* unimplemented io_setup */
	/* 228 */	NULL, /* unimplemented io_destroy */
	/* 229 */	NULL, /* unimplemented io_getevents */
	/* 230 */	NULL, /* unimplemented io_submit */
	/* 231 */	NULL, /* unimplemented io_cancel */
	/* 232 */	NULL, /* set_tid_address */
	/* 233 */	NULL, /* fadvise64 */
	/* 234 */	NULL, /* exit_group */
	/* 235 */	NULL, /* unimplemented lookup_dcookie */
	/* 236 */	NULL, /* epoll_create */
	/* 237 */	NULL, /* epoll_ctl */
	/* 238 */	NULL, /* epoll_wait */
	/* 239 */	NULL, /* unimplemented remap_file_pages */
	/* 240 */	NULL, /* timer_create */
	/* 241 */	NULL, /* timer_settime */
	/* 242 */	NULL, /* timer_gettime */
	/* 243 */	NULL, /* timer_getoverrun */
	/* 244 */	NULL, /* timer_delete */
	/* 245 */	NULL, /* clock_settime */
	/* 246 */	NULL, /* clock_gettime */
	/* 247 */	NULL, /* clock_getres */
	/* 248 */	NULL, /* clock_nanosleep */
	/* 249 */	NULL, /* unimplemented swapcontext */
	/* 250 */	NULL, /* tgkill */
	/* 251 */	NULL, /* utimes */
	/* 252 */	NULL, /* statfs64 */
	/* 253 */	NULL, /* fstatfs64 */
	/* 254 */	NULL, /* fadvise64_64 */
	/* 255 */	NULL, /* unimplemented rtas */
	/* 256 */	NULL, /* unimplemented / * reserved for sys_debug_setcontext * / */
	/* 257 */	NULL, /* unimplemented / * reserved for vserver * / */
	/* 258 */	NULL, /* unimplemented / * reserved for new sys_remap_file_pages * / */
	/* 259 */	NULL, /* unimplemented / * reserved for new sys_mbind * / */
	/* 260 */	NULL, /* unimplemented / * reserved for new sys_get_mempolicy * / */
	/* 261 */	NULL, /* unimplemented / * reserved for new sys_set_mempolicy * / */
	/* 262 */	NULL, /* mq_open */
	/* 263 */	NULL, /* mq_unlink */
	/* 264 */	NULL, /* mq_timedsend */
	/* 265 */	NULL, /* mq_timedreceive */
	/* 266 */	NULL, /* mq_notify */
	/* 267 */	NULL, /* mq_getsetattr */
	/* 268 */	NULL, /* unimplemented kexec_load */
	/* 269 */	NULL, /* unimplemented add_key */
	/* 270 */	NULL, /* unimplemented request_key */
	/* 271 */	NULL, /* unimplemented keyctl */
	/* 272 */	NULL, /* waitid */
	/* 273 */	NULL, /* unimplemented ioprio_set */
	/* 274 */	NULL, /* unimplemented ioprio_get */
	/* 275 */	NULL, /* inotify_init */
	/* 276 */	NULL, /* inotify_add_watch */
	/* 277 */	NULL, /* inotify_rm_watch */
	/* 278 */	NULL, /* unimplemented spu_run */
	/* 279 */	NULL, /* unimplemented spu_create */
	/* 280 */	NULL, /* pselect6 */
	/* 281 */	NULL, /* ppoll */
	/* 282 */	NULL, /* unimplemented unshare */
	/* 283 */	NULL, /* unimplemented splice */
	/* 284 */	NULL, /* unimplemented tee */
	/* 285 */	NULL, /* unimplemented vmsplice */
	/* 286 */	NULL, /* openat */
	/* 287 */	NULL, /* mkdirat */
	/* 288 */	NULL, /* mknodat */
	/* 289 */	NULL, /* fchownat */
	/* 290 */	NULL, /* unimplemented futimesat */
	/* 291 */	NULL, /* fstatat64 */
	/* 292 */	NULL, /* unlinkat */
	/* 293 */	NULL, /* renameat */
	/* 294 */	NULL, /* linkat */
	/* 295 */	NULL, /* symlinkat */
	/* 296 */	NULL, /* readlinkat */
	/* 297 */	NULL, /* fchmodat */
	/* 298 */	NULL, /* faccessat */
	/* 299 */	NULL, /* __futex_set_robust_list */
	/* 300 */	NULL, /* __futex_get_robust_list */
	/* 301 */	NULL, /* unimplemented move_pages */
	/* 302 */	NULL, /* getcpu */
	/* 303 */	NULL, /* epoll_pwait */
	/* 304 */	NULL, /* utimensat */
	/* 305 */	NULL, /* unimplemented signalfd */
	/* 306 */	NULL, /* timerfd_create */
	/* 307 */	NULL, /* eventfd */
	/* 308 */	NULL, /* unimplemented sync_file_range2 */
	/* 309 */	NULL, /* fallocate */
	/* 310 */	NULL, /* unimplemented subpage_prot */
	/* 311 */	NULL, /* timerfd_settime */
	/* 312 */	NULL, /* timerfd_gettime */
	/* 313 */	NULL, /* unimplemented signalfd4 */
	/* 314 */	NULL, /* eventfd2 */
	/* 315 */	NULL, /* epoll_create1 */
	/* 316 */	NULL, /* dup3 */
	/* 317 */	NULL, /* pipe2 */
	/* 318 */	NULL, /* inotify_init1 */
	/* 319 */	NULL, /* unimplemented perf_event_open */
	/* 320 */	NULL, /* preadv */
	/* 321 */	NULL, /* pwritev */
	/* 322 */	NULL, /* unimplemented rt_tgsigqueueinfo */
	/* 323 */	NULL, /* unimplemented fanotify_init */
	/* 324 */	NULL, /* unimplemented fanotify_mark */
	/* 325 */	NULL, /* prlimit64 */
	/* 326 */	NULL, /* unimplemented socket */
	/* 327 */	NULL, /* unimplemented bind */
	/* 328 */	NULL, /* unimplemented connect */
	/* 329 */	NULL, /* unimplemented listen */
	/* 330 */	NULL, /* unimplemented accept */
	/* 331 */	NULL, /* unimplemented getsockname */
	/* 332 */	NULL, /* unimplemented getpeername */
	/* 333 */	NULL, /* unimplemented socketpair */
	/* 334 */	NULL, /* unimplemented send */
	/* 335 */	NULL, /* unimplemented sendto */
	/* 336 */	NULL, /* unimplemented recv */
	/* 337 */	NULL, /* unimplemented recvfrom */
	/* 338 */	NULL, /* unimplemented shutdown */
	/* 339 */	NULL, /* unimplemented setsockopt */
	/* 340 */	NULL, /* unimplemented getsockopt */
	/* 341 */	NULL, /* unimplemented sendmsg */
	/* 342 */	NULL, /* unimplemented recvmsg */
	/* 343 */	NULL, /* recvmmsg */
	/* 344 */	NULL, /* accept4 */
	/* 345 */	NULL, /* unimplemented name_to_handle_at */
	/* 346 */	NULL, /* unimplemented open_by_handle_at */
	/* 347 */	NULL, /* unimplemented clock_adjtime */
	/* 348 */	NULL, /* unimplemented syncfs */
	/* 349 */	NULL, /* sendmmsg */
	/* 350 */	NULL, /* unimplemented setns */
	/* 351 */	NULL, /* unimplemented process_vm_readv */
	/* 352 */	NULL, /* unimplemented process_vm_writev */
	/* 353 */	NULL, /* unimplemented finit_module */
	/* 354 */	NULL, /* unimplemented kcmp */
	/* 355 */	NULL, /* unimplemented sched_setattr */
	/* 356 */	NULL, /* unimplemented sched_getattr */
	/* 357 */	NULL, /* unimplemented renameat2 */
	/* 358 */	NULL, /* unimplemented seccomp */
	/* 359 */	NULL, /* getrandom */
	/* 360 */	NULL, /* unimplemented memfd_create */
	/* 361 */	NULL, /* unimplemented bpf */
	/* 362 */	NULL, /* unimplemented execveat */
	/* 363 */	NULL, /* unimplemented switch_endian */
	/* 364 */	NULL, /* unimplemented userfaultfd */
	/* 365 */	NULL, /* unimplemented membarrier */
	/* 366 */	NULL, /* unimplemented */
	/* 367 */	NULL, /* unimplemented */
	/* 368 */	NULL, /* unimplemented */
	/* 369 */	NULL, /* unimplemented */
	/* 370 */	NULL, /* unimplemented */
	/* 371 */	NULL, /* unimplemented */
	/* 372 */	NULL, /* unimplemented */
	/* 373 */	NULL, /* unimplemented */
	/* 374 */	NULL, /* unimplemented */
	/* 375 */	NULL, /* unimplemented */
	/* 376 */	NULL, /* unimplemented */
	/* 377 */	NULL, /* unimplemented */
	/* 378 */	NULL, /* unimplemented mlock2 */
	/* 379 */	NULL, /* unimplemented copy_file_range */
	/* 380 */	NULL, /* unimplemented preadv2 */
	/* 381 */	NULL, /* unimplemented pwritev2 */
	/* 382 */	NULL, /* unimplemented kexec_file_load */
	/* 383 */	NULL, /* statx */
	/* 384 */	NULL, /* unimplemented */
	/* 385 */	NULL, /* unimplemented */
	/* 386 */	NULL, /* unimplemented */
	/* 387 */	NULL, /* unimplemented */
	/* 388 */	NULL, /* unimplemented */
	/* 389 */	NULL, /* unimplemented */
	/* 390 */	NULL, /* unimplemented */
	/* 391 */	NULL, /* unimplemented */
	/* 392 */	NULL, /* unimplemented */
	/* 393 */	NULL, /* unimplemented */
	/* 394 */	NULL, /* unimplemented */
	/* 395 */	NULL, /* unimplemented */
	/* 396 */	NULL, /* unimplemented */
	/* 397 */	NULL, /* unimplemented */
	/* 398 */	NULL, /* unimplemented */
	/* 399 */	NULL, /* unimplemented */
	/* 400 */	NULL, /* unimplemented */
	/* 401 */	NULL, /* unimplemented */
	/* 402 */	NULL, /* unimplemented */
	/* 403 */	NULL, /* unimplemented */
	/* 404 */	NULL, /* unimplemented */
	/* 405 */	NULL, /* unimplemented */
	/* 406 */	NULL, /* unimplemented */
	/* 407 */	NULL, /* unimplemented */
	/* 408 */	NULL, /* unimplemented */
	/* 409 */	NULL, /* unimplemented */
	/* 410 */	NULL, /* unimplemented */
	/* 411 */	NULL, /* unimplemented */
	/* 412 */	NULL, /* unimplemented */
	/* 413 */	NULL, /* unimplemented */
	/* 414 */	NULL, /* unimplemented */
	/* 415 */	NULL, /* unimplemented */
	/* 416 */	NULL, /* unimplemented */
	/* 417 */	NULL, /* unimplemented */
	/* 418 */	NULL, /* unimplemented */
	/* 419 */	NULL, /* unimplemented */
	/* 420 */	NULL, /* unimplemented */
	/* 421 */	NULL, /* unimplemented */
	/* 422 */	NULL, /* unimplemented */
	/* 423 */	NULL, /* unimplemented */
	/* 424 */	NULL, /* unimplemented */
	/* 425 */	NULL, /* unimplemented */
	/* 426 */	NULL, /* unimplemented */
	/* 427 */	NULL, /* unimplemented */
	/* 428 */	NULL, /* unimplemented */
	/* 429 */	NULL, /* unimplemented */
	/* 430 */	NULL, /* unimplemented */
	/* 431 */	NULL, /* unimplemented */
	/* 432 */	NULL, /* unimplemented */
	/* 433 */	NULL, /* unimplemented */
	/* 434 */	NULL, /* unimplemented */
	/* 435 */	NULL, /* unimplemented */
	/* 436 */	NULL, /* close_range */
	/* 437 */	NULL, /* unimplemented */
	/* 438 */	NULL, /* unimplemented */
	/* 439 */	NULL, /* faccessat2 */
	/* 440 */	NULL, /* unimplemented */
	/* 441 */	NULL, /* epoll_pwait2 */
	/* 442 */	NULL, /* filler */
	/* 443 */	NULL, /* filler */
	/* 444 */	NULL, /* filler */
	/* 445 */	NULL, /* filler */
	/* 446 */	NULL, /* filler */
	/* 447 */	NULL, /* filler */
	/* 448 */	NULL, /* filler */
	/* 449 */	NULL, /* filler */
	/* 450 */	NULL, /* filler */
	/* 451 */	NULL, /* filler */
	/* 452 */	NULL, /* filler */
	/* 453 */	NULL, /* filler */
	/* 454 */	NULL, /* filler */
	/* 455 */	NULL, /* filler */
	/* 456 */	NULL, /* filler */
	/* 457 */	NULL, /* filler */
	/* 458 */	NULL, /* filler */
	/* 459 */	NULL, /* filler */
	/* 460 */	NULL, /* filler */
	/* 461 */	NULL, /* filler */
	/* 462 */	NULL, /* filler */
	/* 463 */	NULL, /* filler */
	/* 464 */	NULL, /* filler */
	/* 465 */	NULL, /* filler */
	/* 466 */	NULL, /* filler */
	/* 467 */	NULL, /* filler */
	/* 468 */	NULL, /* filler */
	/* 469 */	NULL, /* filler */
	/* 470 */	NULL, /* filler */
	/* 471 */	NULL, /* filler */
	/* 472 */	NULL, /* filler */
	/* 473 */	NULL, /* filler */
	/* 474 */	NULL, /* filler */
	/* 475 */	NULL, /* filler */
	/* 476 */	NULL, /* filler */
	/* 477 */	NULL, /* filler */
	/* 478 */	NULL, /* filler */
	/* 479 */	NULL, /* filler */
	/* 480 */	NULL, /* filler */
	/* 481 */	NULL, /* filler */
	/* 482 */	NULL, /* filler */
	/* 483 */	NULL, /* filler */
	/* 484 */	NULL, /* filler */
	/* 485 */	NULL, /* filler */
	/* 486 */	NULL, /* filler */
	/* 487 */	NULL, /* filler */
	/* 488 */	NULL, /* filler */
	/* 489 */	NULL, /* filler */
	/* 490 */	NULL, /* filler */
	/* 491 */	NULL, /* filler */
	/* 492 */	NULL, /* filler */
	/* 493 */	NULL, /* filler */
	/* 494 */	NULL, /* filler */
	/* 495 */	NULL, /* filler */
	/* 496 */	NULL, /* filler */
	/* 497 */	NULL, /* filler */
	/* 498 */	NULL, /* filler */
	/* 499 */	NULL, /* filler */
	/* 500 */	NULL, /* filler */
	/* 501 */	NULL, /* filler */
	/* 502 */	NULL, /* filler */
	/* 503 */	NULL, /* filler */
	/* 504 */	NULL, /* filler */
	/* 505 */	NULL, /* filler */
	/* 506 */	NULL, /* filler */
	/* 507 */	NULL, /* filler */
	/* 508 */	NULL, /* filler */
	/* 509 */	NULL, /* filler */
	/* 510 */	NULL, /* filler */
	/* 511 */	NULL, /* filler */
};
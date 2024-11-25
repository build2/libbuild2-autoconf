// HAVE_STRUCT_RUSAGE_RU_MAXRSS : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_STRUCT_RUSAGE_RU_MAXRSS

/* Presence of the ru_maxrss field in the rusage structure, which
 * tracks the maximum resident set size (memory usage) of a process.
 * Since glibc 2.0, FreeBSD 4.0, OpenBSD 2.0, NetBSD 1.3, MacOS 10
 * Solaris 7
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 0)    || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(4, 0)  || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199610) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 3) || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 0) || \
    ((defined(__sun) && defined(__SVR4)) || defined(__sun__))
#  define HAVE_STRUCT_RUSAGE_RU_MAXRSS 1
#endif

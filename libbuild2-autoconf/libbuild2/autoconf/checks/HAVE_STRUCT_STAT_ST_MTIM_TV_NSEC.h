// HAVE_STRUCT_STAT_ST_MTIM_TV_NSEC : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_STRUCT_STAT_ST_MTIM_TV_NSEC

/* Presence of the st_mtim.tv_nsec field in the stat structure,
 * which provides nanosecond resolution for file modification times.
 * Since glibc 2.12, FreeBSD 5.0, OpenBSD 5.6, NetBSD 6.0, MacOS 10.5
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 12) || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(5, 0)  || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(201411) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(6, 0) || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 5)
#  define HAVE_STRUCT_STAT_ST_MTIM_TV_NSEC 1
#endif

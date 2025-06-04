// HAVE_STRUCT_STAT_ST_MTIM_TV_NSEC : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_STRUCT_STAT_ST_MTIM_TV_NSEC

/* Check for the presence of the st_mtim.tv_nsec field in the stat structure,
 * which provides nanosecond resolution for file modification times.
 *
 * Since glibc 2.12, FreeBSD 9.0, OpenBSD 2.0 (October 1996), NetBSD 7.0.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 12)    || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(9, 0)   || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199610) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(7, 0)
#  define HAVE_STRUCT_STAT_ST_MTIM_TV_NSEC 1
#endif

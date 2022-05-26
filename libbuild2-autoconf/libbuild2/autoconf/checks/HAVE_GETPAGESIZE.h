// HAVE_GETPAGESIZE : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_GETPAGESIZE

/* Since glibc 2.0 at the latest (but broken until 2.1), FreeBSD 2.0, OpenBSD
 * 2.2, NetBSD 1.3, Mac OS (from BSD).
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 1)     || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(2, 0)   || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199712) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 3)    || \
    defined(BUILD2_AUTOCONF_MACOS)
#  define HAVE_GETPAGESIZE 1
#endif

// HAVE_ATEXIT : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_ATEXIT

/* Since glibc 2.2.3, FreeBSD 1.0, OpenBSD 2.2, NetBSD 1.3, Mac OS (from BSD),
 * Windows 95 at the latest.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 3)     || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(1, 0)   || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199712) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 3)    || \
    defined(BUILD2_AUTOCONF_MACOS)         || \
    defined(_WIN32)
#  define HAVE_ATEXIT 1
#endif

// HAVE_ISSETUGID : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_ISSETUGID

/* Since OpenBSD 2.0, FreeBSD 3.0, NetBSD 1.5, Mac OS X, Solaris
 */
#if BUILD2_AUTOCONF_OPENBSD_PREREQ(200601) || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(2, 3)   || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(5, 0)    || \
    defined(BUILD2_AUTOCONF_MACOS)         || \
    ((defined(__sun) && defined(__SVR4)) || defined(__sun__))
#  define HAVE_ISSETUGID 1
#endif

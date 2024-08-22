// HAVE_ISFINITE : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_ISFINITE

/* Since Linux/glibc 2.0, FreeBSD 5.1, OpenBSD 4.4, NetBSD 1.3, Mac OS, Solaris
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 0)     || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(5, 1)   || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(200910) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 3)    || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 6)    || \
    BUILD2_AUTOCONF_MINGW_PREREQ(1, 0)     || \
    defined(BUILD2_AUTOCONF_MACOS)         || \
    defined(_WIN32)                        || \
    ((defined(__sun) && defined(__SVR4)) || defined(__sun__))
#  define HAVE_ISFINITE 1
#endif

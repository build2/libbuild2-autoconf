// HAVE_COSF : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_COSF

/* Check for the cosf() function.
 *
 * Available on FreeBSD 1.0, OpenBSD 2.0, NetBSD 1.0, MacOS 10.10, Linux/glibc
 * 2.10, Solaris, Windows including MinGW.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 10)    || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(1, 0)   || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199510) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 0)    || \
    BUILD2_AUTOCONF_MINGW_PREREQ(1, 0)     || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 10)   || \
    defined(_WIN32)                        || \
    ((defined(__sun) && defined(__SVR4)) || defined(__sun__))
#  define HAVE_COSF 1
#endif

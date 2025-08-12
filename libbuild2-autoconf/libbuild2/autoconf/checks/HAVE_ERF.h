// HAVE_ERF : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_ERF

/* Check for the erf() function.
 * erf() computes the error function of a floating-point number.
 *
 * Available on Linux/glibc 2.19, FreeBSD 1.0, OpenBSD 2.1, NetBSD 1.3, MacOS
 * (exact version is unclear but for a while now), Solaris, Windows including
 * MinGW.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 19)    || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(1, 0)   || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199105) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 3)    || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 0)    || \
    defined(_WIN32)                        || \
    ((defined(__sun) && defined(__SVR4)) || defined(__sun__))
#  define HAVE_ERF 1
#endif

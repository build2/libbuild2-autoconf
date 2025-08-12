// HAVE_ISINF : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_ISINF

/* Check for the isinf() function.
 *
 * Available on Linux/glibc, FreeBSD, NetBSD, OpenBSD, MacOS 10.2, Solaris,
 * Windows including MinGW.
 */
#if defined(__GLIBC__)                  || \
    defined(__FreeBSD__)                || \
    defined(__NetBSD__)                 || \
    defined(__OpenBSD__)                || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 2) || \
    defined(_WIN32)                     || \
    ((defined(__sun) && defined(__SVR4)) || defined(__sun__))
#  define HAVE_ISINF 1
#endif

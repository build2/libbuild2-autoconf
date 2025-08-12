// HAVE_ATANF : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_ATANF

/* Check for the atanf() function.
 *
 * Available on OpenBSD 2.0, FreeBSD 3.0, NetBSD 1.3, Mac OS 10.0, Linux/glibc
 * 2.0, Solaris, Windows including MinGW and Cygwin.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 0)     || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(3, 0)   || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199610) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 3)    || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 0)    || \
    defined(_WIN32)                        || \
    defined(__CYGWIN__)                    || \
    ((defined(__sun) && defined(__SVR4)) || defined(__sun__))
#  define HAVE_ATANF 1
#endif

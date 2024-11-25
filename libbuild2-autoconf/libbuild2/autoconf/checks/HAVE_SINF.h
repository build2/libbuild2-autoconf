// HAVE_SINF : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_SINF

/* Since Linux/glibc 2.1, FreeBSD 5.0, OpenBSD 3.0, NetBSD 1.6, Mac OS 10.3,
 * Windows, MinGW 3.0, Solaris 10
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 1)     || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(5, 0)   || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(200112) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 6)    || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 3)    || \
    BUILD2_AUTOCONF_MINGW_PREREQ(3, 0)     || \
    defined(_WIN32)                        || \
    ((defined(__sun) && defined(__SVR4)) || defined(__sun__))
#  define HAVE_SINF 1
#endif

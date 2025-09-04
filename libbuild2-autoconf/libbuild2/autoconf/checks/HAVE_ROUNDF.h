// HAVE_ROUNDF : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_ROUNDF

/*  Since glibc 2.1, 4.3BSD, FreeBSD 5.3, OpenBSD 4.0 (November 2006), NetBSD
 *  2.0, MacOS 10.2, Windows, Mingw-w64, POSIX.1, SVr4
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 1)     || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(5, 3)   || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(200611) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(2, 0)    || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 2)    || \
    defined(_WIN32)                        || \
    defined(__MINGW32__)                   || \
    ((defined(__sun) && defined(__SVR4)) || defined(__sun__))
#  define HAVE_ROUNDF 1
#endif

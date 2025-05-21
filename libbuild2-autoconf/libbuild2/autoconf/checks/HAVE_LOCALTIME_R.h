// HAVE_LOCALTIME_R : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_LOCALTIME_R

/*  Check for the localtime_r() function.
 *
 *  Since glibc 2.0, 4.3BSD, FreeBSD 8.0, OpenBSD 2.5 (May 1999), NetBSD 1.4,
 *  MacOS 10.0, Mingw-w64 2.0, POSIX.1c, SVr4. Not available on Windows
 *  (except Mingw-w64).
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 0)     || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(8, 0)   || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199905) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 4)    || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 2)    || \
    BUILD2_AUTOCONF_MINGW_PREREQ(2, 0)     || \
    ((defined(__sun) && defined(__SVR4)) || defined(__sun__))
#  define HAVE_LOCALTIME_R 1
#endif

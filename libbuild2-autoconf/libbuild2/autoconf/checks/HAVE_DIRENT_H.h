// HAVE_DIRENT_H : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_DIRENT_H

/*  Since
 * 4.2BSD, FreeBSD 2.2, OpenBSD 2.2, NetBSD 6.0, MacOS 10.10, Mingw-w64 2.0
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 10)    || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(1, 0)  || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199712) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(6, 0) || \
    BUILD2_AUTOCONF_MINGW_PREREQ(1, 0) || \
    defined(BUILD2_AUTOCONF_MACOS) || \
    ((defined(__sun) && defined(__SVR4)) || defined(__sun__))
#  define HAVE_DIRENT_H 1
#endif

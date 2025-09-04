// HAVE_RINT : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_RINT

/* Since glibc 2.19, FreeBSD 1.0, OpenBSD 2.2, NetBSD 1.3 and MacOS, Win32.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 19)     || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(1, 0)   || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199712) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 3)    || \
    defined(BUILD2_AUTOCONF_MACOS)         || \
    defined(_WIN32)
#  define HAVE_RINT 1
#endif

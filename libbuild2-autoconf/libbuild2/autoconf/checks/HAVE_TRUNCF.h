// HAVE_TRUNCF : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_TRUNCF

/* Since glibc 2.1, FreeBSD 5.3, OpenBSD 4.0, NetBSD 4.0 and MacOS, Win32.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 1)     || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(5, 3)   || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(200611) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(4, 0)    || \
    defined(BUILD2_AUTOCONF_MACOS)         || \
    defined(_WIN32)
#  define HAVE_TRUNCF 1
#endif

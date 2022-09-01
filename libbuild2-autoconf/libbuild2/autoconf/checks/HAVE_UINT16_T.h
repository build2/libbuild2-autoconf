// HAVE_UINT16_T : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_UINT16_T

/* Since Linux/glibc 2.0, OpenBSD 2.0, FreeBSD 5.0, NetBSD 1.6, Mac OS
 * and win32.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 0) || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(5, 0) || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199610) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 6) || \
    defined(BUILD2_AUTOCONF_MACOS) || \
    defined(_WIN32)
#  define HAVE_UINT16_T 1
#endif

// HAVE_GETIFADDRS : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_GETIFADDRS

/* Since Linux/glibc 2.3, OpenBSD 2.9, FreeBSD 4.1, NetBSD 1.5, and Mac OS
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 3) || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(4, 1)|| \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(200106) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 5) || \
    defined(BUILD2_AUTOCONF_MACOS)
#  define HAVE_GETIFADDRS 1
#endif

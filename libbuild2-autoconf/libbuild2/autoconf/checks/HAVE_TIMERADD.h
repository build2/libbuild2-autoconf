// HAVE_TIMERADD : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_TIMERADD

/* Since Linux/glibc 2.1, OpenBSD 2.9, FreeBSD 5.0, NetBSD 6.0 and Mac OS
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 1) || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(5, 0) || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(200106) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(6, 0) || \
    defined(BUILD2_AUTOCONF_MACOS)
#  define HAVE_TIMERADD 1
#endif

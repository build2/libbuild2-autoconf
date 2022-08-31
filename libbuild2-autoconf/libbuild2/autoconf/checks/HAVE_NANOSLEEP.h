// HAVE_NANOSLEEP : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_NANOSLEEP

/* Since OpenBSD 2.1, FreeBSD 3.0, NetBSD 1.3, Mac OS X < 10.0,
 * glibc 2.1 (?)
 */
#if defined(__linux__)                     || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199706) || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(3, 0)   || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 3)    || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 0)    || \
    BUILD2_AUTOCONF_GLIBC_PREREQ(2, 1)
#  define HAVE_NANOSLEEP 1
#endif

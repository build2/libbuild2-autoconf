// HAVE_UMASK : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_UMASK

/*  Since glibc 1.09, FreeBSD 1.0, OpenBSD 2.0, NetBSD 1.0 and MacOS
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(1, 9)    || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(1, 0)  || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199610) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 0) || \
    defined(BUILD2_AUTOCONF_MACOS)
#  define HAVE_UMASK 1
#endif

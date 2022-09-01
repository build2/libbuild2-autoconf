// HAVE_ERRNO_H : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_ERRNO_H

/* Since Linux/glibc 2.1, OpenBSD 2.0, FreeBSD 1.0, NetBSD 1.0, Mac OS
 * and win32.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 1) || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(1, 0) || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199610) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 0) || \
    defined(BUILD2_AUTOCONF_MACOS) || \
    defined(_WIN32)
#  define HAVE_ERRNO_H 1
#endif

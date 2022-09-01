// HAVE_SYS_TIME_H : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_SYS_TIME_H

/* Since 4.2BSD (OpenBSD, FreeBSD, Mac OS X), NetBSD 6.0
 */
#if defined(__linux__)                      || \
    defined(__FreeBSD__)                    || \
    defined(__OpenBSD__)                    || \
    defined(__NetBSD__)                     || \
    defined(BUILD2_AUTOCONF_MACOS)          || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(6, 0)
#  define HAVE_SYS_TIME_H 1
#endif

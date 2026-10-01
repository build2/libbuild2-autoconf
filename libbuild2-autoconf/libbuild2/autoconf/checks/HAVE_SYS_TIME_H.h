// HAVE_SYS_TIME_H : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_SYS_TIME_H

/* Check for the <sys/time.h> header.
 *
 * Available since Linux/glibc, FreeBSD, OpenBSD, NetBSD 6.0, and Mac OS.
 * Not available on Windows except MinGW.
 */
#if defined(__linux__)                      || \
    defined(__FreeBSD__)                    || \
    defined(__OpenBSD__)                    || \
    defined(__NetBSD__)                     || \
    defined(__MINGW32__)                    || \
    defined(BUILD2_AUTOCONF_MACOS)          || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(6, 0)
#  define HAVE_SYS_TIME_H 1
#endif

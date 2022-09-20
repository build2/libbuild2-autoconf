// HAVE_POLL_H : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_POLL_H

/* Since Linux 2.1.23/glibc (all versions; emulated using select() on older
 * kernels), FreeBSD (all versions), OpenBSD (all versions), NetBSD 1.3, Mac
 * OS (all versions).
 */
#if defined(__GLIBC__)                  || \
    defined(__FreeBSD__)                || \
    defined(__OpenBSD__)                || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 3) || \
    defined(BUILD2_AUTOCONF_MACOS)
#  define HAVE_POLL_H 1
#endif

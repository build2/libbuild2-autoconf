// HAVE_UINT32_MAX : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_UINT32_MAX

/* Check for the UINT32_MAX macro defined in <stdint.h>.
 *
 * Available since Linux/glibc 2.0, OpenBSD 2.0, FreeBSD 5.0, NetBSD 1.6, Mac
 * OS and Windows (same as HAVE_STDINT_H).
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 0) || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(5, 0) || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199610) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 6) || \
    defined(BUILD2_AUTOCONF_MACOS) || \
    defined(_WIN32)
#  define HAVE_UINT32_MAX 1
#endif

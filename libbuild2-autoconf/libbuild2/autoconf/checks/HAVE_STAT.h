// HAVE_STAT : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_STAT

/* Check for the stat() function which retrieves file status information.
 *
 * Commonly available in POSIX systems. Not available on Windows (except
 * Mingw-w64).
 */
#if defined(__GLIBC__)                   || \
    defined(__FreeBSD__)                 || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 3)  || \
    defined(__OpenBSD__)                 || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 14) || \
    BUILD2_AUTOCONF_MINGW_PREREQ(2, 0)
#  define HAVE_STAT 1
#endif

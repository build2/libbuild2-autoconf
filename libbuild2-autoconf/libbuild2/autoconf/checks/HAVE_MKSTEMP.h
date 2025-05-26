// HAVE_MKSTEMP : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_MKSTEMP

/* Check for the mkstemp() function.
 *
 * glibc; 4.3BSD and thus FreeBSD, OpenBSD, NetBSD, and Mac OS X since the
 * beginning; Mingw-w64 4.0. Not available on Windows (except Mingw-w64).
 */
#if defined(__GLIBC__)                 || \
    defined(__FreeBSD__)               || \
    defined(__NetBSD__)                || \
    defined(__OpenBSD__)               || \
    BUILD2_AUTOCONF_MINGW_PREREQ(4, 0) || \
    defined(BUILD2_AUTOCONF_MACOS)
#  define HAVE_MKSTEMP 1
#endif

// HAVE_STRNCASECMP : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_STRNCASECMP

/* Check for the strncasecmp() function which performs a case-insensitive
 * comparison of two strings up to a specified number of characters.
 *
 * It is a POSIX function. Not available on Windows (except Mingw-w64).
 *
 * Note that strcasecmp() was added at the same time in all of the systems I
 * checked so be sure to replicate any changes to HAVE_STRCASECMP.h.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(1, 9)  || \
    defined(__FreeBSD__)                || \
    defined(__NetBSD__)                 || \
    defined(__OpenBSD__)                || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 2) || \
    defined(__MINGW32__)
#  define HAVE_STRNCASECMP 1
#endif

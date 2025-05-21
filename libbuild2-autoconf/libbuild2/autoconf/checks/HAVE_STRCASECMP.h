// HAVE_STRCASECMP : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_STRCASECMP

/* Check for the strcasecmp() function which compares two strings
 * case-insensitively.
 *
 * It is a POSIX function. Not available on Windows (except Mingw-w64).
 *
 * Note that strncasecmp() was added at the same time in all of the systems I
 * checked so be sure to replicate any changes to HAVE_STRNCASECMP.h.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(1, 9)  || \
    defined(__FreeBSD__)                || \
    defined(__NetBSD__)                 || \
    defined(__OpenBSD__)                || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 2) || \
    defined(__MINGW32__)
#  define HAVE_STRCASECMP 1
#endif

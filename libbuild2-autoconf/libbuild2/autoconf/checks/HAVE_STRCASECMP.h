// HAVE_STRCASECMP : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_STRCASECMP

/* This checks for strcasecmp(), which compares two strings
 * case-insensitively. It is a POSIX-compliant function.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(1, 9)  || \
    defined(__FreeBSD__)                || \
    defined(__NetBSD__)                 || \
    defined(__OpenBSD__)                || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 2) || \
    defined(__MINGW32__)
#  define HAVE_STRCASECMP 1
#endif

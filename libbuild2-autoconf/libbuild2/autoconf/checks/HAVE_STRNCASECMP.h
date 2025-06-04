// HAVE_STRNCASECMP : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_STRNCASECMP

/* This checks for the availability of the strncasecmp() function,
 * which performs a case-insensitive comparison of two strings up
 * to a specified number of characters.
 * It is part of the POSIX standard and is widely available on Unix-like systems.
 */
#if defined(__linux__) || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(1, 0) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 0) || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199706) || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 0)
#  define HAVE_STRNCASECMP 1
#endif

// HAVE_STRNLEN : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_STRNLEN

/* Check for the strnlen() function which calculates the length of a string up
 * to a specified maximum.
 *
 * POSIX, OpenBSD 4.8 (November 2010).
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 0)     || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(8, 0)   || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(6, 0)    || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(201011) || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 7)    || \
    defined(_WIN32)                        || \
    defined(__MINGW32__)                   || \
    defined(__CYGWIN__)
#  define HAVE_STRNLEN 1
#endif

// HAVE_TRUNC : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_TRUNC

/* Checks for the trunc() function from <math.h>.
 *
 * Since glibc 2.1, FreeBSD 5.3, OpenBSD 4.0 (November 2006), NetBSD 4.0,
 * MacOS 10.2.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 1)     || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(5, 3)   || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(200611) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(4, 0)    || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 2)    || \
    defined(_WIN32)                        || \
    defined(__MINGW32__)
#  define HAVE_TRUNC 1
#endif

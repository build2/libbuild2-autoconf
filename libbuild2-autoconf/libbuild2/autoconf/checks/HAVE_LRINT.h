// HAVE_LRINT : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_LRINT

/* Check for the lrint() function.
 *
 * Available on Linux/glibc 2.1, FreeBSD 5.4, OpenBSD 3.9, NetBSD 3.1, MacOS
 * (exact version is unclear but for a while now), Windows including MinGW.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 1)     || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(5, 4)   || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(200601) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(3, 1)    || \
    defined(BUILD2_AUTOCONF_MACOS)         || \
    defined(_WIN32)
#  define HAVE_LRINT 1
#endif

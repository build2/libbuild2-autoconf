// HAVE_EXPF : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_EXPF

// NOTE: keep consistent with HAVE_EXP2.

/* Check for the expf() function.
 *
 * Available on FreeBSD 2.3, OpenBSD 4.4, NetBSD 6.0, MacOS (exact version is
 * unclear but for a while now), Linux/glibc 2.1, Solaris, Windows including
 * MinGW.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 1)     || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(2, 3)   || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(200811) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(6, 0)    || \
    BUILD2_AUTOCONF_MINGW_PREREQ(1, 0)     || \
    defined(BUILD2_AUTOCONF_MACOS)         || \
    defined(_WIN32)
#  define HAVE_EXPF 1
#endif

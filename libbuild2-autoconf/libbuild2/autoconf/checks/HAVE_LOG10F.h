// HAVE_LOG10F : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_LOG10F

/* Check for the log10f() function.
 *
 * Available on FreeBSD 1.0, OpenBSD 2.0, NetBSD 1.0, MacOS (exact version is
 * unclear but for a while now), Linux/glibc 2.19, Windows including MinGW.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 19)    || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(1, 0)   || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199510) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 0)    || \
    BUILD2_AUTOCONF_MINGW_PREREQ(1, 0)     || \
    defined(BUILD2_AUTOCONF_MACOS)         || \
    defined(_WIN32)
#  define HAVE_LOG10F 1
#endif

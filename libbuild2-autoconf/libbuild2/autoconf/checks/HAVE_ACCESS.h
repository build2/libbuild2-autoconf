// HAVE_ACCESS : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_ACCESS

/* Check for the access() function.
 *
 * Since glibc 2.1, BSD 4.3, FreeBSD 1.0, OpenBSD 2.0 (October 1996), NetBSD
 * 1.0, MacOS, Windows (including MinGW, Mingw-w64), POSIX.1, SVr4.
 *
 * Note that on Windows access() is deprecated in favor of _access() because
 * it is a POSIX function that 'doesn't follow the Standard C rules for
 * implementation-specific names'. It is still supported but a warning will
 * be issued unless the _CRT_NONSTDC_NO_WARNINGS preprocessor macro is
 * defined.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 1)     || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(1, 0)   || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199610) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 0)    || \
    defined(BUILD2_AUTOCONF_MACOS)         || \
    (defined(__sun) && defined(__SVR4))    || \
    defined(_WIN32)                        || \
    defined(__MINGW32__)
#  define HAVE_ACCESS 1
#endif

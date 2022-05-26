// HAVE_ISATTY : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_ISATTY

/* All versions of glibc, FreeBSD, OpenBSD, NetBSD, Mac OS, Windows.
 */
#if defined(__GLIBC__)             || \
    defined(__FreeBSD__)           || \
    defined(__OpenBSD__)           || \
    defined(__NetBSD__)            || \
    defined(BUILD2_AUTOCONF_MACOS) || \
    defined(_WIN32)
#  define HAVE_ISATTY 1
#endif

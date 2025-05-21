// HAVE_GETOPT : BUILD2_AUTOCONF_LIBC_VERSION

#undef HAVE_GETOPT

/* Check for the getopt() function.
 *
 * Since POSIX.2 and 4.3BSD. Not available on Windows (except Mingw-w64).
 */
#if defined(__GLIBC__)             || \
    defined(__FreeBSD__)           || \
    defined(__NetBSD__)            || \
    defined(__OpenBSD__)           || \
    defined(BUILD2_AUTOCONF_MACOS) || \
    defined(__MINGW32__)           || \
    ((defined(__sun) && defined(__SVR4)) || defined(__sun__))
#  define HAVE_GETOPT 1
#endif

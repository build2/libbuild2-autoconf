// HAVE_GETRUSAGE : BUILD2_AUTOCONF_LIBC_VERSION

#undef HAVE_GETRUSAGE

/* Check for the getrusage() function.
 *
 * Since POSIX.1-2001, SVr4, and 4.3BSD.
 */
#if defined(__GLIBC__)             || \
    defined(__FreeBSD__)           || \
    defined(__NetBSD__)            || \
    defined(__OpenBSD__)           || \
    defined(BUILD2_AUTOCONF_MACOS) || \
    ((defined(__sun) && defined(__SVR4)) || defined(__sun__))
#  define HAVE_GETRUSAGE 1
#endif

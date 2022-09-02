// socklen_t : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef socklen_t

/* Since 4.xBSD, SunOS
 * The Single UNIX Specification, Version 2
 *   <sys/socket.h> makes available a type, socklen_t, which is
 *   an unsigned opaque integral type of length of at least 32 bits.
 *   To forestall portability problems, it is recommended that
 *   applications should not use values larger than 232 - 1.
 */
#if defined(__linux__)                  || \
    defined(__FreeBSD__)                || \
    defined(__OpenBSD__)                || \
    defined(__NetBSD__)                 || \
    defined(BUILD2_AUTOCONF_MACOS)      || \
    (defined(__sun) && defined(__SVR4)) || \
    defined(__CYGWIN__)
    /* If available, we do nothing. */
#elif defined(_WIN32)
    /* If available, we do nothing. */
#else
    /* Else define it to unsigned int (suggested fallback by libevent). */
#   define socklen_t unsigned int
#endif

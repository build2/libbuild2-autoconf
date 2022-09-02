// ssize_t : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef ssize_t

/* POSIX and MinGW (which also has <sys/types.h> that defines ssize_t), Windows
 */
#if defined(__linux__)                  || \
    defined(__FreeBSD__)                || \
    defined(__OpenBSD__)                || \
    defined(__NetBSD__)                 || \
    defined(BUILD2_AUTOCONF_MACOS)      || \
    defined(__MINGW32__)                || \
    (defined(__sun) && defined(__SVR4)) || \
    defined(__CYGWIN__)
   /* If available, we do nothing. */
#elif defined(_WIN32)
#   include <basetsd.h>
#   define ssize_t SSIZE_T
#else
   /* Else define it to int (suggested fallback by libevent). */
#   define ssize_t int
#endif

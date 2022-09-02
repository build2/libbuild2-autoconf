// HAVE_FCNTL_H : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_FCNTL_H

/* Note that there is <fcntl.h> on Windows (both MSVC and MinGW) though its
 * declarations are not the same as on POSIX. But it does exist.
 */

#if defined(__linux__)              || \
    defined(__FreeBSD__)            || \
    defined(__OpenBSD__)            || \
    defined(__NetBSD__)             || \
    defined(BUILD2_AUTOCONF_MACOS)  || \
    defined(_WIN32)
#  define HAVE_FCNTL_H 1
#endif

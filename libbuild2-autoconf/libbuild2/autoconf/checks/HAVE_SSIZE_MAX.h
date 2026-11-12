// HAVE_SSIZE_MAX : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_SSIZE_MAX

/* Check for the SSIZE_MAX macro defined in <limits.h> on some platforms.
 *
 * Available on Linux with POSIX, FreeBSD, and Mac OS (will assume always).
 * Not available on Windows except on MinGW. NetBSD and OpenBSD are TODO.
 */
#if defined(__linux__)
#  if defined(__USE_POSIX)
#    define HAVE_SSIZE_MAX 1
#  endif
#elif defined(__FreeBSD__)
#  define HAVE_SSIZE_MAX 1
#elif defined(_WIN32)
#  if defined(__MINGW32__)
#    define HAVE_SSIZE_MAX 1
#  endif
#endif

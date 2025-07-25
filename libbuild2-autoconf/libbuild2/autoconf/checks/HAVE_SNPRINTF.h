// HAVE_SNPRINTF : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_SNPRINTF

/* Check for the snprintf() function which safely formats strings into a
 * buffer.
 *
 * It is part of the C99 standard and widely available.
 *
 * Note that vsnprintf() was added at the same time in all of the systems I
 * checked so be sure to replicate any changes to HAVE_VSNPRINTF.h.
 */
#if defined(__GLIBC__)                  || \
    defined(__FreeBSD__)                || \
    defined(__NetBSD__)                 || \
    defined(__OpenBSD__)                || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 2) || \
    defined(_WIN32)                     || \
    defined(__MINGW32__)
#  define HAVE_SNPRINTF 1
#endif

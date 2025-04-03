// HAVE_SNPRINTF : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_SNPRINTF

/* This checks for the snprintf() function, which safely
 * formats strings into a buffer.
 * It’s part of the C99 standard and widely available.
 */
#if defined(__linux__) || \
    defined(__FreeBSD__) || \
    defined(__NetBSD__) || \
    defined(__OpenBSD__) || \
    defined(__APPLE__) || \
    defined(_WIN32)
#  define HAVE_SNPRINTF 1
#endif

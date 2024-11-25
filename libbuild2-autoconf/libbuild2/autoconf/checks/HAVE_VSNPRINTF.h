// HAVE_VSNPRINTF : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_VSNPRINTF

/* Checks for the vsnprintf() function, which formats
 * a string into a buffer with variable arguments.
 */
#if defined(__linux__) || \
    defined(__APPLE__) || \
    defined(__FreeBSD__) || \
    defined(__NetBSD__) || \
    defined(__OpenBSD__) || \
    defined(_WIN32)
#  define HAVE_VSNPRINTF 1
#endif

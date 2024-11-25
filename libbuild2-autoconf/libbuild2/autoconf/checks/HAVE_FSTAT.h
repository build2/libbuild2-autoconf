// HAVE_FSTAT : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_FSTAT

/* Checks for the fstat() function, which retrieves
 * file information using a file descriptor.
 */
#if defined(__linux__) || defined(__APPLE__) || \
    defined(__FreeBSD__) || \
    defined(__NetBSD__) || \
    defined(__OpenBSD__) || \
    defined(_WIN32)
#  define HAVE_FSTAT 1
#endif

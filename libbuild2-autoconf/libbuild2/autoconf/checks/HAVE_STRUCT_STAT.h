// HAVE_STRUCT_STAT : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_STRUCT_STAT

/* Checks for the stat structure, used with the stat
 * system call to retrieve file status information.
 */
#if defined(__linux__) || \
    defined(__APPLE__) || \
    defined(__FreeBSD__) || \
    defined(__NetBSD__) || \
    defined(__OpenBSD__) || \
    defined(_WIN32)
#  define HAVE_STRUCT_STAT 1
#endif

// HAVE_STAT : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_STAT

/* This checks for the stat system call, used to retrieve file status information.
 * Commonly available in POSIX systems.
 */
#if defined(__linux__) || \
    defined(__APPLE__) || \
    defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
#  define HAVE_STAT 1
#endif

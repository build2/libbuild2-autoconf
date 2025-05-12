// HAVE_FTRUNCATE : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_FTRUNCATE

/* This checks if ftruncate() is available, which truncates
 * a file to a specified length.
 */
#if defined(__linux__) || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(1, 0) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 3) || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 0)
#  define HAVE_FTRUNCATE 1
#endif

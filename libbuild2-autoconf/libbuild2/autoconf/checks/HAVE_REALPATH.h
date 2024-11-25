// HAVE_REALPATH : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_REALPATH

/* This checks for the realpath() function, which resolves absolute paths.
 */
#if defined(__linux__) || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(1, 0) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 3) || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 0)
#  define HAVE_REALPATH 1
#endif

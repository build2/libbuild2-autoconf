// HAVE_PATHCONF : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_PATHCONF

/* Checks for pathconf(), which retrieves system configuration
 * values for a specific path.
 */
#if defined(__linux__) || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(1, 0) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 0) || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 0)
#  define HAVE_PATHCONF 1
#endif

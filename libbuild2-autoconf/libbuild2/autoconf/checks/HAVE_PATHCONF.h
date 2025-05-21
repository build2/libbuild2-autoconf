// HAVE_PATHCONF : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_PATHCONF

/* Check for the pathconf() function which retrieves system configuration
 * values for a specific path.
 */
#if defined(__GLIBC__)   || \
    defined(__FreeBSD__) || \
    defined(__NetBSD__)  || \
    defined(__OpenBSD__) || \
    defined(BUILD2_AUTOCONF_MACOS)
#  define HAVE_PATHCONF 1
#endif

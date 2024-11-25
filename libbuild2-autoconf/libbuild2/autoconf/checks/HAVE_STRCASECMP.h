// HAVE_STRCASECMP : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_STRCASECMP

/* This checks for strcasecmp(), which compares two
 * strings case-insensitively.
 * It is a POSIX-compliant function.
 */
#if defined(__linux__) || \
    defined(__FreeBSD__) || \
    defined(__NetBSD__) || \
    defined(__OpenBSD__) || \
    defined(__APPLE__)
#  define HAVE_STRCASECMP 1
#endif

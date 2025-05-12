// HAVE_FACCESSAT : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_FACCESSAT

/* Checks for the faccessat() function, which tests file access
 * permissions relative to a directory file descriptor.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 4) || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(8, 0) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(6, 0) || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 10)
#  define HAVE_FACCESSAT 1
#endif

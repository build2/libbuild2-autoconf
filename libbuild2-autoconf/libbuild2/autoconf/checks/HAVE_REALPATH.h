// HAVE_REALPATH : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_REALPATH

/* Check for the realpath() function which resolves absolute paths.
 *
 * Since glibc 1.90, FreeBSD 2.2.0, NetBSD 1.1, OpenBSD (with initial NetBSD
 * import), macOS 10.2.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(1, 90)  || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(2, 2) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 1)  || \
    defined(__OpenBSD__)                 || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 2)
#  define HAVE_REALPATH 1
#endif

// HAVE_PIPE : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_PIPE

/* Since Version 3 AT&T UNIX (older than 1979),
 * glibc 2.9.
 */
#if defined(__FreeBSD__) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(2, 0)    || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 7)    || \
    BUILD2_AUTOCONF_GLIBC_PREREQ(2, 36)
#  define HAVE_PIPE 1
#endif

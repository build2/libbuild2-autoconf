// HAVE_SLEEP : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_SLEEP

/* Since Version 4/7 AT&T UNIX.
 * glibc 2.1 (?)
 */
#if defined(__linux__)                     || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199706) || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(3, 0)   || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 3)    || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 0)    || \
    BUILD2_AUTOCONF_GLIBC_PREREQ(2, 1)
#  define HAVE_SLEEP 1
#endif

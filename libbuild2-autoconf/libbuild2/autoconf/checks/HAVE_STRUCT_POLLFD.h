// HAVE_STRUCT_POLLFD : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_STRUCT_POLLFD

/* Presence of the pollfd structure, used for the poll() system call,
 * which monitors multiple file descriptors.
 * Since glibc 2.0, FreeBSD 3.0, OpenBSD 2.0, NetBSD 1.3, MacOS 10
 * Solaris 2.6
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 0)    || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(3, 0)  || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199610) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 3) || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 0) || \
    ((defined(__sun) && defined(__SVR4)) || defined(__sun__))
#  define HAVE_STRUCT_POLLFD 1
#endif

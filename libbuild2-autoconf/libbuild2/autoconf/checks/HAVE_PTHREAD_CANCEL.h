// HAVE_PTHREAD_CANCEL : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_PTHREAD_CANCEL

/* Presence of the pthread_cancel() function.
 * Since glibc 2.0, FreeBSD 5.2, OpenBSD 3.3, NetBSD 3.0, MacOS 10.0
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 0)    || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(5, 2)  || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(200305) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(3, 0) || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 0) || \
    ((defined(__sun) && defined(__SVR4)) || defined(__sun__))
#  define HAVE_PTHREAD_CANCEL 1
#endif

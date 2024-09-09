// HAVE_PTHREAD_SETNAME_NP : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_PTHREAD_SETNAME_NP

/* Presence of the pthread_setname_np() function, which is a
 * non-standard POSIX function used to set the name of a thread.
 * Since glibc 2.12, FreeBSD 7.0, NetBSD 8.0, MacOS 10.6
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 12) || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(7, 0) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(8, 0) || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 6)
#  define HAVE_PTHREAD_SETNAME_NP 1
#endif

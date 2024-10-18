// HAVE_PTHREAD_SET_NAME_NP : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_PTHREAD_SET_NAME_NP

/* Presence of the pthread_set_name_np() function, which is a
 * non-standard POSIX function used to set the name of a thread.
 * Since glibc 2.12, FreeBSD 7.0, NetBSD 8.0, MacOS 10.6
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 12) || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(9, 0) || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(20131101) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(7, 0)
#  define HAVE_PTHREAD_SET_NAME_NP 1
#endif

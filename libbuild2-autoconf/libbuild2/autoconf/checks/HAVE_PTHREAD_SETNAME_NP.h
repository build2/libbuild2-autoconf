// HAVE_PTHREAD_SETNAME_NP : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_PTHREAD_SETNAME_NP

/* Check for the presence of the pthread_setname_np() function,
 * which sets the name of a thread. This function is available on:
 * - glibc 2.12+
 * - FreeBSD 9.0+
 * - NetBSD 8.0+
 * - macOS 10.6+
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 12)    || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(9, 0)   || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(8, 0)    || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 6)
#  define HAVE_PTHREAD_SETNAME_NP 1
#endif

// HAVE_SLEEP : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_SLEEP

/* Check for the presence of the sleep() function, which pauses the
 * program for a specified number of seconds. This function is widely
 * available on UNIX-like systems, including:
 * - Linux (all versions with glibc 2.0+)
 * - FreeBSD 3.0+, NetBSD 1.3+, OpenBSD 2.1+, macOS 10.0+
 */
#if defined(__linux__) || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199706) || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(3, 0)   || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 3)    || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 0)    || \
    BUILD2_AUTOCONF_GLIBC_PREREQ(2, 0)
#  define HAVE_SLEEP 1
#endif

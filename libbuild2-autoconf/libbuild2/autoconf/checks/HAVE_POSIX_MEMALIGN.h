// HAVE_POSIX_MEMALIGN : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_POSIX_MEMALIGN

/* Check for the posix_memalign() function.
 *
 * Since glibc 2.1.91, FreeBSD 7.0, OpenBSD 4.8 (November 2010), NetBSD 5.0,
 * MacOS 10.6.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 2)     || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(7, 0)   || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(201011) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(5, 0)    || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 6)
#  define HAVE_POSIX_MEMALIGN 1
#endif

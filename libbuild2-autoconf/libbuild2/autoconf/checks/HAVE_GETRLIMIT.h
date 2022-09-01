// HAVE_GETRLIMIT : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_GETRLIMIT

/* Since 4.2BSD (Linux, OpenBSD, FreeBSD, NetBSD, Mac OS X),
 * glibc 1.90
 */
#if defined(__FreeBSD__)            || \
    defined(__OpenBSD__)            || \
    defined(__NetBSD__)             || \
    defined(BUILD2_AUTOCONF_MACOS)  || \
    BUILD2_AUTOCONF_GLIBC_PREREQ(1, 90)
#  define HAVE_GETRLIMIT 1
#endif

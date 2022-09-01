// HAVE_USLEEP : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_USLEEP

/* Since 4.3BSD (OpenBSD, FreeBSD, NetBSD, Mac OS X),
 * glibc 2.1 (?)
 */
#if defined(__FreeBSD__)                || \
    defined(__OpenBSD__)                || \
    defined(__NetBSD__)                 || \
    defined(BUILD2_AUTOCONF_MACOS)      || \
    BUILD2_AUTOCONF_GLIBC_PREREQ(2, 1)
#  define HAVE_USLEEP 1
#endif

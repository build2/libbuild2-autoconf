// HAVE_STRSEP : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_STRSEP

/* Since 4.4BSD (OpenBSD, FreeBSD, NetBSD, Mac OS X),
 * glibc 1.09
 */
#if defined(__FreeBSD__)            || \
    defined(__OpenBSD__)            || \
    defined(__NetBSD__)             || \
    defined(BUILD2_AUTOCONF_MACOS)  || \
    BUILD2_AUTOCONF_GLIBC_PREREQ(1, 9)
#  define HAVE_STRSEP 1
#endif

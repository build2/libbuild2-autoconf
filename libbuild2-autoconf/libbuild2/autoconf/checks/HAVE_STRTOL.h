// HAVE_STRTOL : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_STRTOL

/* Since 'ISO C90' (OpenBSD, FreeBSD, NetBSD, Mac OS X),
 * glibc 1.90
 */
#if defined(__FreeBSD__)            || \
    defined(__OpenBSD__)            || \
    defined(__NetBSD__)             || \
    defined(BUILD2_AUTOCONF_MACOS)  || \
    BUILD2_AUTOCONF_GLIBC_PREREQ(1, 90)
#  define HAVE_STRTOL 1
#endif

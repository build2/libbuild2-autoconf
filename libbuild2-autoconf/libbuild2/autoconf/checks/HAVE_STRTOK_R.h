// HAVE_STRTOK_R : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_STRTOK_R

/* Since 4.4BSD (OpenBSD, FreeBSD, NetBSD, Mac OS X), glibc 2.0, and Mingw-w64
 * 3.3.0.
 */
#if defined(__FreeBSD__)               || \
    defined(__OpenBSD__)               || \
    defined(__NetBSD__)                || \
    defined(BUILD2_AUTOCONF_MACOS)     || \
    BUILD2_AUTOCONF_GLIBC_PREREQ(2, 0) || \
    BUILD2_AUTOCONF_MINGW_PREREQ(3, 3)
#  define HAVE_STRTOK_R 1
#endif

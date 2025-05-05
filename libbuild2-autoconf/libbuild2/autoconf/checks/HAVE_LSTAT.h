// HAVE_LSTAT : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_LSTAT

/* 
 * lstat() is available in:
 * - glibc since 2.19
 * - BSD systems (including MacOS)
 * - Solaris
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 19) || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(1, 0) || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199510) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 3) || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 0) || \
    ((defined(__sun) && defined(__SVR4)) || defined(__sun__))
#  define HAVE_LSTAT 1
#endif

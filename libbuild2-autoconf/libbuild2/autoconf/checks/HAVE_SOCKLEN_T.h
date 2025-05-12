// HAVE_SOCKLEN_T : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_SOCKLEN_T

/* socklen_t is available in:
 * - glibc since 2.0
 * - BSD systems (including MacOS)
 * - Solaris, Cygwin
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 0) || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(4, 0) || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199510) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 0) || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 0) || \
    (defined(__sun) && defined(__SVR4)) || \
    defined(__CYGWIN__)
#  define HAVE_SOCKLEN_T 1
#endif

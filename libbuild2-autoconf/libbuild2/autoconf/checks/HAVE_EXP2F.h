// HAVE_EXP2F : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_EXP2F

/*  Since glibc 2.1, 4.3BSD, FreeBSD 2.3, OpenBSD 4.4, NetBSD 6.0, MacOS v?, Mingw-w64 2.0
 *        Windows.
 *  NOTE: This just replicates HAVE_EXP2.h
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 1) || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(2, 3) || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(200811) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(6, 0) || \
    BUILD2_AUTOCONF_MINGW_PREREQ(1, 0) || \
    defined(__APPLE__) || \
    defined(_WIN32)
#  define HAVE_EXP2F 1
#endif

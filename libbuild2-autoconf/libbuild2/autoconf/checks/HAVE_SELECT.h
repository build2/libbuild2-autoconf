// HAVE_SELECT : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_SELECT

/* Since OpenBSD 5.4, FreeBSD 5.0, NetBSD x, Mac OS 10.3 (assuming it was
 * added roughly at the same time as OpenBSD 5.4), Linux Kernel 2.6.16
 */
#if defined(__linux__)                     || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(201311) || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(5, 0)   || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(2, 0)    || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 0)    || \
    BUILD2_AUTOCONF_GLIBC_PREREQ(2, 36)
#  define HAVE_SELECT 1
#endif

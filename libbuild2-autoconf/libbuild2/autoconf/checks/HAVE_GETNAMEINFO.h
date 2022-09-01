// HAVE_GETNAMEINFO : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_GETNAMEINFO

/* Since Linux/glibc 2.1, OpenBSD 2.9, FreeBSD 4.0, NetBSD 1.5, and Mac OS X
 * (hard to tell but based on the manpages available online it looks like
 * Tiger at the latest).
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 1) || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(4, 0)|| \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(200106) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 5) || \
    defined(BUILD2_AUTOCONF_MACOS)
#  define HAVE_GETNAMEINFO 1
#endif

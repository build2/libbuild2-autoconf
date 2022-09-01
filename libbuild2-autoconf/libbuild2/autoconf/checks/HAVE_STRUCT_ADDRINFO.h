// HAVE_STRUCT_ADDRINFO : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_STRUCT_ADDRINFO

/* Since Linux/glibc 2.4, OpenBSD 2.9, FreeBSD 3.5, NetBSD 1.5, and Mac OS
 * (hard to tell but based on the manpages available online it looks like
 * Tiger at the latest).
 * NOTE: Assuming same as HAVE_GETADDRINFO
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 4)      || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(200106)  || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(3, 5)    || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 5)     || \
    defined(BUILD2_AUTOCONF_MACOS)
#  define HAVE_STRUCT_ADDRINFO 1
#endif

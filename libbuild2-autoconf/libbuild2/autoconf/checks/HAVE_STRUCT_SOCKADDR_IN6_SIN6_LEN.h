// HAVE_STRUCT_SOCKADDR_IN6_SIN6_LEN : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_STRUCT_SOCKADDR_IN6_SIN6_LEN

/* Since OpenBSD ~4.2, FreeBSD ~7.0, NetBSD 2.1, Mac OS X 10.6
 */
#if BUILD2_AUTOCONF_OPENBSD_PREREQ(200705)  || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(7, 0)    || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(2, 1)     || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 6)
#  define HAVE_STRUCT_SOCKADDR_IN6_SIN6_LEN 1
#endif

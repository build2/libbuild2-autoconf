// HAVE_STRUCT_SOCKADDR_STORAGE_SS_FAMILY : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_STRUCT_SOCKADDR_STORAGE_SS_FAMILY

/* Since Linux/glibc 2.3, OpenBSD >=2.7, FreeBSD >=4.0, NetBSD >=1.5, Mac OS X 10.0,
 * Windows
 *
 * NOTE: RFC2553 (<1999)    - defines __ss_len & __ss_family
 *       XNET draft (>1999) - defines ss_len & ss_family
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 3)      || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(200015)  || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(4, 0)    || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 5)     || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 0)     || \
    defined(_WIN32)
#  define HAVE_STRUCT_SOCKADDR_STORAGE_SS_FAMILY 1
#endif

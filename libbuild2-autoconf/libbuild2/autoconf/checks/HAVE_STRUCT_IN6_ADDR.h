// HAVE_STRUCT_IN6_ADDR : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_STRUCT_IN6_ADDR

/* Since Linux/glibc 2.1, OpenBSD 2.9, FreeBSD 3.5, NetBSD 1.5, and Mac OS X, Windows
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 1)      || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(3, 5)    || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(200106)  || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 5)     || \
    defined(BUILD2_AUTOCONF_MACOS)          || \
    defined(_WIN32)
#  define HAVE_STRUCT_IN6_ADDR 1
#endif

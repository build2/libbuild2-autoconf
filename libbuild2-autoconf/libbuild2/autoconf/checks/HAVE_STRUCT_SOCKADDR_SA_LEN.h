// HAVE_STRUCT_SOCKADDR_SA_LEN : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_STRUCT_SOCKADDR_SA_LEN

/* Presence of the sa_len field in the sockaddr structure,
 * which defines the length of the address structure.
 * FreeBSD 4.0, OpenBSD 2.0, NetBSD 1.5, MacOS 10
 * Solaris 7
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 0)    || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(4, 0)  || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199610) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 5) || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 0)
#  define HAVE_STRUCT_SOCKADDR_SA_LEN 1
#endif

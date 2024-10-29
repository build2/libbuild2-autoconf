// HAVE_STRUCT_SOCKADDR_SA_LEN : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_STRUCT_SOCKADDR_SA_LEN

/* Check for the presence of the sa_len field in the sockaddr structure,
 * which defines the length of the address structure.
 * Supported on FreeBSD 4.0, OpenBSD 2.0, NetBSD 1.5, and macOS 10.0+
 */
#if BUILD2_AUTOCONF_FREEBSD_PREREQ(4, 0)   || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199610) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 5)    || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 0)
#  define HAVE_STRUCT_SOCKADDR_SA_LEN 1
#endif

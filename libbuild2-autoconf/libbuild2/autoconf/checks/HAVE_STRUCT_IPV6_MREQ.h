// HAVE_STRUCT_IPV6_MREQ : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_STRUCT_IPV6_MREQ

/* Pof the group_source_req structure, used for managing IP multicast group
 * subscriptions with source filtering, typically found in newer networking libraries.
 * Since glibc 2.1, FreeBSD 5.0, OpenBSD 3.0, NetBSD 1.5, MacOS 10
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 1)    || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(5, 0)  || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(200112) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 5) || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 0)
#  define HAVE_STRUCT_IPV6_MREQ 1
#endif

// HAVE_STRUCT_IP_MREQ_SOURCE : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_STRUCT_IP_MREQ_SOURCE

/* Presence of the ip_mreq_source structure, used for IP
 * multicast source filtering in IPv4.
 * Since glibc 2.1, FreeBSD 9.0
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 1) || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(9, 0)
#  define HAVE_STRUCT_IP_MREQ_SOURCE 1
#endif

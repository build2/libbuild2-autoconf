// HAVE_NETINET_IN6_H : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_NETINET_IN6_H

/* On Linux the IPv6 constructs are defined in netinet/in.h and on FreeBSD
 * netinet/in.h includes netinet6/in6.h (note: not netinet/) so the latter
 * should not be included directly.
*/
#if defined(__OpenBSD__) || \
    defined(__NetBSD__)  || \
    defined(BUILD2_AUTOCONF_MACOS)
#  define HAVE_NETINET_IN6_H 1
#endif

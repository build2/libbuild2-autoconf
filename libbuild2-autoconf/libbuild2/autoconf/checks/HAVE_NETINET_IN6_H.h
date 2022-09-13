// HAVE_NETINET_IN6_H

/* Looks like netinet/in6.h only exists on System V-derived OSes like AIX,
 * HP-UX, Solaris, and Illumos.
 *
 * On Linux the IPv6 constructs are defined in netinet/in.h and on FreeBSD,
 * OpenBSD, NetBSD, and MacOS netinet/in.h includes netinet6/in6.h (note: not
 * netinet/) so the latter should not be included directly.
 */
#undef HAVE_NETINET_IN6_H

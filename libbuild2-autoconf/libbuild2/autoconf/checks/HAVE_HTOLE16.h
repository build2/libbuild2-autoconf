// HAVE_HTOLE16 : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_HTOLE16

/* Check for the htole16() macro/function which converts a 16-bit integer from
 * host to little-endian format.
 *
 * Since OpenBSD 2.1 (June 1997).
 *
 * Note that htole{16,32,64}() were added at the same time on all platforms
 * checked so be sure to replicate any changes to HAVE_HTLOE32.h and
 * HAVE_HTLOE64.h.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 9)     || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(5, 1)   || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 5)    || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199706)
#  define HAVE_HTOLE16 1
#endif

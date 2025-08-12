// HAVE___BSWAP_16 : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE___BSWAP_16

/* Checks for the availability of the __bswap_16() macro or intrinsic.
 * __bswap_16() swaps the byte order of a 16-bit integer. It is typically
 * defined in system headers such as <byteswap.h> on GNU-based systems or
 * equivalent headers on other platforms.
 *
 * Available on OpenBSD 3.3, FreeBSD 5.0, NetBSD 1.6, Linux/glibc 2.9. Not
 * available on MacOS or Windows including MinGW.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 9)     || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(5, 0)   || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(200305) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 6)
#  define HAVE___BSWAP_16 1
#endif

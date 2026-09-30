// HAVE_ENDIAN_H : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_ENDIAN_H

/* Check for the <endian.h> header, which provides macros for byte-order
 * manipulation.
 *
 * Available since Linux/glibc, NetBSD, and OpenBSD. Not available on
 * Mac OS or on Windows, including MinGW.
 */
#if defined(__GLIBC__)  || \
    defined(__NetBSD__) || \
    defined(__OpenBSD__)
#  define HAVE_ENDIAN_H 1
#endif

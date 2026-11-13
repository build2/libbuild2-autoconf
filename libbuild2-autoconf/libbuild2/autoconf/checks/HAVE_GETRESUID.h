// HAVE_GETRESUID : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_GETRESUID

/* Check for the getresuid() function from the unistd.h header.
 *
 * Available since glibc 2.3.2 with _GNU_SOURCE, FreeBSD 4.0. Not available
 * on Mac OS or Windows.
 */
#if (BUILD2_AUTOCONF_GLIBC_PREREQ(2, 3) && defined(_GNU_SOURCE)) || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(4, 0)
#  define HAVE_GETRESUID 1
#endif

// HAVE_SECTION_DATA_REL_RO : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_SECTION_DATA_REL_RO

/* Check for .data.rel.ro section support.
 * .data.rel.ro is a linker section for read-only relocatable data.
 *
 * Available on Linux/glibc 2.3, FreeBSD 7.0, OpenBSD, NetBSD 7.0, Solaris.
 * Not available on Windows including MinGW.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 3)     || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(7, 0)   || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(201609) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(7, 0)    || \
    ((defined(__sun) && defined(__SVR4)) || defined(__sun__))
#  define HAVE_SECTION_DATA_REL_RO 1
#endif

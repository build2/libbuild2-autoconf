// HAVE_CLOSE_RANGE : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_CLOSE_RANGE

/* Since FreeBSD 12.2 (based on their online manual pages) and glibc 2.34.
 */
#if BUILD2_AUTOCONF_FREEBSD_PREREQ(12, 2) || \
    BUILD2_AUTOCONF_GLIBC_PREREQ(2, 34)
#  define HAVE_CLOSE_RANGE 1
#endif

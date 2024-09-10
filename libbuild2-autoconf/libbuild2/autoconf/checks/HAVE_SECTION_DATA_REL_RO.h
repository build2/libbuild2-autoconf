// HAVE_SECTION_DATA_REL_RO : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_SECTION_DATA_REL_RO

/* Presence of the .data.rel.ro section, which is used for
 * placing read-only data that may be relocated at runtime.
 * Since glibc 2.3, FreeBSD 11.0, MacOS 10.12, Solaris 10
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 3)    || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(11, 0)  || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 12) || \
    ((defined(__sun) && defined(__SVR4)) || defined(__sun__))
#  define HAVE_SECTION_DATA_REL_RO 1
#endif

// HAVE_STATX : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_STATX

/* Since Linux 4.11/glibc 2.28.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 28)
#  define HAVE_STATX 1
#endif

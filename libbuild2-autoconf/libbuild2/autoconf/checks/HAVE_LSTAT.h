// HAVE_LSTAT : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_LSTAT

/* Since glibc 2.19.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 19)
#  define HAVE_LSTAT 1
#endif

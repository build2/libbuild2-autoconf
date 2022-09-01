// HAVE_RENAMEAT2 : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_RENAMEAT2

/* Since Linux 3.15/glibc 2.28. */

#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 28)
#  define HAVE_RENAMEAT2 1
#endif

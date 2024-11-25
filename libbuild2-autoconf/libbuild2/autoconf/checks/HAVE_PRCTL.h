// HAVE_PRCTL : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_PRCTL

/* Presence of the prctl() system call.
 * Since glibc 2.0
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 0)
#  define HAVE_PRCTL 1
#endif

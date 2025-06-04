// HAVE_MEMALIGN : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_MEMALIGN

/* Presence of memalign() function.
 * Since glibc 2.0, Solaris
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 0) || \
    ((defined(__sun) && defined(__SVR4)) || defined(__sun__))
#  define HAVE_MEMALIGN 1
#endif

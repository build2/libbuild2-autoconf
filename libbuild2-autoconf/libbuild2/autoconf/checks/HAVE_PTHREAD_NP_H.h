// HAVE_PTHREAD_NP_H : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_PTHREAD_NP_H

/* Existence of the pthread_np.h header, which provides non-standard POSIX (NP).
 * FreeBSD 5.0
 */
#if BUILD2_AUTOCONF_FREEBSD_PREREQ(5, 0)
#  define HAVE_PTHREAD_NP_H 1
#endif

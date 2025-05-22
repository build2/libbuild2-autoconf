// HAVE_PTHREAD_NP_H : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_PTHREAD_NP_H

/* Check for the pthread_np.h header which provides non-portable pthread
 * functions.
 *
 * Since FreeBSD 5.1 and OpenBSD 2.4 (December 1998).
 *
 * Note that this check is indentical to HAVE_PTHREAD_SET_NAME_NP because
 * pthread_set_name_np() is declared in pthread_np.h so be sure to replicate
 * any changes to HAVE_PTHREAD_SET_NAME_NP.h.
 */
#if BUILD2_AUTOCONF_FREEBSD_PREREQ(5, 1) || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199812)
#  define HAVE_PTHREAD_NP_H 1
#endif

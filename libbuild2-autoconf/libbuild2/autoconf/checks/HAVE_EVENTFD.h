// HAVE_EVENTFD : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_EVENTFD

/* Since Linux/glibc 2.8, FreeBSD 13.
 *
 * @@ TODO eventfd() looks likely to be added to NetBSD 10 which does not yet
 *    have a release date.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 8) || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(13, 0)
#  define HAVE_EVENTFD 1
#endif

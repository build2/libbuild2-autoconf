// HAVE_POLLTS : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_POLLTS

/* Since NetBSD 3.0.
 */
#if BUILD2_AUTOCONF_NETBSD_PREREQ(3, 0)
#  define HAVE_POLLTS 1
#endif

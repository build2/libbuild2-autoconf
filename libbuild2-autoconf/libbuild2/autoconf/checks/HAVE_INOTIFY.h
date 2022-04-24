// HAVE_INOTIFY : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_INOTIFY

/* Since Linux 2.6.3/glibc 2.4.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 4)
#  define HAVE_INOTIFY 1
#endif

// HAVE_EPOLL : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_EPOLL

/* Since glibc 2.3.2.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 3)
#  define HAVE_EPOLL 1
#endif

// HAVE_TIMERFD_CREATE : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_TIMERFD_CREATE

/* Since Linux/glibc 2.8 and Mac OS
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 8) || \
    defined(BUILD2_AUTOCONF_MACOS)
#  define HAVE_TIMERFD_CREATE 1
#endif

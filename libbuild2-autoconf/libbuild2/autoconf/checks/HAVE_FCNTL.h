// HAVE_FCNTL : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_FCNTL
/* Since BSD 4.2 (1983)
 */
#if defined(__linux__)   || \
    defined(__FreeBSD__) || \
    defined(__OpenBSD__) || \
    defined(__NetBSD__)  || \
    defined(BUILD2_AUTOCONF_MACOS)
#  define HAVE_FCNTL 1
#endif

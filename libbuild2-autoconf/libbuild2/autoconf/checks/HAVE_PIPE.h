// HAVE_PIPE : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_PIPE

/* Since Version 3 AT&T UNIX (older than 1979).
 * Linux, FreeBSD, OpenBSD, NetBSD, Mac OS X, Solaris
 */
#if defined(__linux__)                    || \
    defined(__FreeBSD__)                  || \
    defined(__OpenBSD__)                  || \
    defined(__NetBSD__)                   || \
    defined(BUILD2_AUTOCONF_MACOS)        || \
    ((defined(__sun) && defined(__SVR4)) || defined(__sun__))
#  define HAVE_PIPE 1
#endif

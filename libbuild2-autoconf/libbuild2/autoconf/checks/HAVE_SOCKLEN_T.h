// HAVE_SOCKLEN_T : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_SOCKLEN_T

/* Check for the socklen_t type.
 *
 * glibc 2.0.x (so round up to 2.1), BSD systems (including MacOS), OpenBSD
 * 2.5 (May 1999), Windows, Mingw-w64, Cygwin, Solaris.
 *
 * On Windows the winsock2 header ws2tcpip.h defines socklen_t. Mingw-w64 has
 * had socklen_t (also in ws2tcpip.h) since v1.0.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 1)     || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(4, 0)   || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199905) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 4)    || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 3)    || \
    defined(_WIN32)                        || \
    defined(__MINGW32__)                   || \
    defined(__CYGWIN__)                    || \
    (defined(__sun) && defined(__SVR4))
#  define HAVE_SOCKLEN_T 1
#endif

// HAVE_CBRT : BUILD2_AUTOCONF_LIBC_VERSION

#undef HAVE_CBRT

/* Since C99, POSIX.1-2001, 4.3BSD,
 * OpenBSD 2.1, FreeBSD 2.0, glibc 2.19, Windows, Solaris
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 19)     || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(2, 0)  || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199706) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 3) || \
    defined(_WIN32) || \
    defined(__MINGW32__) || \
    ((defined(__sun) && defined(__SVR4)) || defined(__sun__))
#  define HAVE_CBRT 1
#endif


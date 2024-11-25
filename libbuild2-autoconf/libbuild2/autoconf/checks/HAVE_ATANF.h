// HAVE_ATANF : BUILD2_AUTOCONF_LIBC_VERSION

#undef HAVE_ATANF

/* Presence of the atan2() function, which is a
 * non-standard POSIX function used to set the name of a thread.
 * Since glibc 2.0, FreeBSD 1.0, OpenBSD 1.0, NetBSD 1.0, MacOS 10.0
 * Solaris 2.0, Windows, MinGW
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 0)    || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(3, 0)  || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199610) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 3) || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 0) || \
    defined(_WIN32) || \
    defined(__MINGW32__) || \
    defined(__CYGWIN__) || \
    ((defined(__sun) && defined(__SVR4)) || defined(__sun__))
#  define HAVE_ATANF 1
#endif


// HAVE_GMTIME_R : BUILD2_AUTOCONF_LIBC_VERSION

#undef HAVE_GMTIME_R

/* Since POSIX.2,
 * OpenBSD 2.1, FreeBSD 1.0, NetBSD 1.3, glibc 2.0, Solaris, macOS
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 0) || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(1, 0) || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199105) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 3) || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 0) || \
    defined(__MINGW32__) || \
    ((defined(__sun) && defined(__SVR4)) || defined(__sun__)) || \
    defined(__ANDROID__) || \
    defined(__CYGWIN__)
#  define HAVE_GMTIME_R 1
#endif

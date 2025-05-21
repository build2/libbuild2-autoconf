// HAVE_GMTIME_R : BUILD2_AUTOCONF_LIBC_VERSION

#undef HAVE_GMTIME_R

/* Check for the gmtime_r() function.
 *
 * Since POSIX.2, glibc 2.0, FreeBSD 8.0, OpenBSD 2.7 (June 2000), NetBSD 1.3,
 * macOS, Mingw-w64 (since before v1.0), Solaris. Not available on Windows
 * (except Mingw-w64).
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 0)     || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(8, 0)   || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(200006) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 3)    || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 0)    || \
    defined(__MINGW32__)                   || \
    defined(__CYGWIN__)                    || \
    ((defined(__sun) && defined(__SVR4)) || defined(__sun__))
#  define HAVE_GMTIME_R 1
#endif

// HAVE_GETRUSAGE : BUILD2_AUTOCONF_LIBC_VERSION

#undef HAVE_GETRUSAGE

/* Since POSIX.1-2001, SVr4, 4.3BSD,
 * OpenBSD 2.1, FreeBSD 1.0, NetBSD 1.3, glibc 2.33, Solaris
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 33)     || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(1, 0)  || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199105) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 3) || \
    defined(BUILD2_AUTOCONF_MACOS) || \
    ((defined(__sun) && defined(__SVR4)) || defined(__sun__))
#  define HAVE_GETRUSAGE 1
#endif

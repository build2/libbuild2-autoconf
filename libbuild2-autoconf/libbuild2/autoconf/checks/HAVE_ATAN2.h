// HAVE_ATAN2 : BUILD2_AUTOCONF_LIBC_VERSION

#undef HAVE_ATAN2

/* Since ANSI C89/ISO C99, OpenBSD 2.6
 */
#if (!defined(BUILD2_AUTOCONF_MACOS) && !defined(__NetBSD__) && !defined(__sun)) && \
    BUILD2_AUTOCONF_GLIBC_PREREQ(2, 0) || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(1, 0) || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199105) || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 10) || \
    BUILD2_AUTOCONF_MINGW_PREREQ(6, 0) || \
    (defined(__sun) && defined(__SVR4))
#  define HAVE_ATAN2 1
#endif


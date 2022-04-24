// HAVE_LINKAT : BUILD2_AUTOCONF_LIBC_VERSION

#undef HAVE_LINKAT

/* Since Linux 2.6.16/glibc 2.4, FreeBSD 8.0, OpenBSD 5.0, NetBSD 7.0 (it was
 * only partially implemented in earlier versions according to the manpage),
 * Mac OS (all versions).
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 4)     || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(8, 0)   || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(201111) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(7, 0)    || \
    (defined(__APPLE__) && defined(__MACH__))
#  define HAVE_LINKAT 1
#endif

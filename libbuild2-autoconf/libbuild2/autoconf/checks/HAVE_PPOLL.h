// HAVE_PPOLL : BUILD2_AUTOCONF_LIBC_VERSION

#undef HAVE_PPOLL

/* Since Linux 2.6.16/glibc 2.4, FreeBSD 11, OpenBSD 5.4.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 4)    || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(11, 0) || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(201311)
#  define HAVE_PPOLL 1
#endif

// HAVE_SA_FAMILY_T : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_SA_FAMILY_T

/* Since Linux/glibc 2.1, OpenBSD >=2.7, FreeBSD >=4.0, NetBSD >=1.5, Mac OS X 10.0
 * NOTE: POSIX.1g (2000) specifies this type name for the 'sa_family' member.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 1)      || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(200015)  || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(4, 0)    || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 5)     || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 0)
#  define HAVE_SA_FAMILY_T 1
#endif

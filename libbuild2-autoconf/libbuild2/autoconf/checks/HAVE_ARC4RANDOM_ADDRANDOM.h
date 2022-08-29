// HAVE_ARC4RANDOM_ADDRANDOM : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_ARC4RANDOM_ADDRANDOM

/* Since OpenBSD 2.1, FreeBSD 2.3, NetBSD 2.0, and Mac OS X (10.7 assuming
 * it was implemented at the same time as the other `arc4random` functions)
 */
#if BUILD2_AUTOCONF_OPENBSD_PREREQ(199706) || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(2, 3)   || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(2, 0)    || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 7)
#  define HAVE_ARC4RANDOM_ADDRANDOM 1
#endif

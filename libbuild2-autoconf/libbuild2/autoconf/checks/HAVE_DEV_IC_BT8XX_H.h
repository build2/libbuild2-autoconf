// HAVE_DEV_IC_BT8XX_H : BUILD2_AUTOCONF_LIBC_VERSION

#undef HAVE_DEV_IC_BT8XX_H

/* Check for dev/ic/bt8xx.h, which provides Brooktree video capture
 * driver interfaces on BSD-based systems. Available since:
 * - FreeBSD 2.2+
 * - OpenBSD 2.3+ (1998)
 * - NetBSD 1.5+
 *
 * This header is not relevant for glibc-based systems.
 */
#if BUILD2_AUTOCONF_FREEBSD_PREREQ(2, 2)   || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199805) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 5)
#  define HAVE_DEV_IC_BT8XX_H 1
#endif

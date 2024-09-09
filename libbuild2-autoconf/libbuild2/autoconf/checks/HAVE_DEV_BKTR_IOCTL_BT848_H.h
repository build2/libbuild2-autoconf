// HAVE_DEV_BKTR_IOCTL_BT848_H : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_DEV_BKTR_IOCTL_BT848_H

/* Presence of <dev/bktr/ioctl_bt848.h>.
 * Since FreeBSD 4.0
 */
#if BUILD2_AUTOCONF_FREEBSD_PREREQ(4, 0)
#  define HAVE_DEV_BKTR_IOCTL_BT848_H 1
#endif

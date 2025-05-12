// HAVE_MACHINE_IOCTL_METEOR_H : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_MACHINE_IOCTL_METEOR_H

/* Presence of <machine/ioctl_meteor.h>.
 * Since FreeBSD 4.0
 */
#if BUILD2_AUTOCONF_FREEBSD_PREREQ(4, 0)
#  define HAVE_MACHINE_IOCTL_METEOR_H 1
#endif

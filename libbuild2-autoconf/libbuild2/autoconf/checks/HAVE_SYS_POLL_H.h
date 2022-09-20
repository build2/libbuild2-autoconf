// HAVE_SYS_POLL_H : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_SYS_POLL_H

/* All use poll.h: FreeBSD, OpenBSD, NetBSD, Mac OS.
 * Since glibc 2.0.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 0)
#  define HAVE_SYS_POLL_H 1
#endif

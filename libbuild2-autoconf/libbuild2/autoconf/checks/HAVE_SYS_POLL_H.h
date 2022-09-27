// HAVE_SYS_POLL_H : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_SYS_POLL_H

/* Since glibc 2.0.
 * FreeBSD, OpenBSD, NetBSD, Mac OS: 
 * All use poll.h though sys/poll.h still exists.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 0) || \
    defined(__FreeBSD__)               || \
    defined(__OpenBSD__)               || \
    defined(__NetBSD__)                || \
    defined(BUILD2_AUTOCONF_MACOS)
#  define HAVE_SYS_POLL_H 1
#endif

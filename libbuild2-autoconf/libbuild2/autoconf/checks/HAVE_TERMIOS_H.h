// HAVE_TERMIOS_H : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_TERMIOS_H

/* Presence of termios.h header, which provides an API for terminal I/O settings,
 * commonly used for managing terminal attributes (e.g., baud rate, control flags).
 * Since glibc 2.0, FreeBSD 2.0, OpenBSD 2.0, NetBSD 1.0, MacOS 10, Solaris 2.0
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 0)    || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(2, 0)  || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199610) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 0) || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 0) || \
    ((defined(__sun) && defined(__SVR4)) || defined(__sun__))
#  define HAVE_TERMIOS_H 1
#endif

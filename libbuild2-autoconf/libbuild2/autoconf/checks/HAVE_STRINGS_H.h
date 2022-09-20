// HAVE_STRINGS_H : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_STRINGS_H

/* Since 4.4BSD (OpenBSD 2.2, FreeBSD 1.0, NetBSD 1.3, Mac OS X 10.0),
 * glibc 2.0. Note that while MinGW also provides it, its contents
 * could be omitted if the NO_OLDNAMES macro is defined. So let's
 * exclude MinGW for now.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 0)     || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(1, 0)   || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199712) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 3)    || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 0)
#  define HAVE_STRINGS_H 1
#endif

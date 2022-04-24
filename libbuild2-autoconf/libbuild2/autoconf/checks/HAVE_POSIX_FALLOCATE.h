// HAVE_POSIX_FALLOCATE : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_POSIX_FALLOCATE

/* Since Linux/glibc 2.2, FreeBSD 9.0
 *
 * posix_fallocate(3) on Linux says since glibc 2.1.94 but use 2.2 as
 * https://sourceware.org/glibc/wiki/Glibc%20Timeline does not show that
 * version and the glibc macros can't check for patch versions.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 2) || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(9, 0)
#  define HAVE_POSIX_FALLOCATE 1
#endif

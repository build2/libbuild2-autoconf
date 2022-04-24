// HAVE_GETENTROPY : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_GETENTROPY

/* Since Linux/glibc 2.25, OpenBSD 5.6, FreeBSD 12, and Mac OS 12.
 *
 * @@ TODO Update when NetBSD releases its support (see
 *    https://mail-index.netbsd.org/tech-userlevel/2020/05/02/msg012333.html).
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 25)    || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(12, 0)  || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(201411) || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 12)
#  define HAVE_GETENTROPY 1
#endif

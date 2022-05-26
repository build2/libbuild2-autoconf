// HAVE_NEWLOCALE : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_NEWLOCALE

/* Note: see also HAVE_USELOCALE. */

/* Since glibc 2.3, FreeBSD 9.1, OpenBSD 6.2, and Mac OS X (hard to tell but
 * based on the manpages available online it looks like Tiger at the latest).
 *
 * @@ TODO Update when NetBSD adds support for newlocale. According to
 *    https://man.netbsd.org/newlocale.3 it's only in CURRENT at the time of
 *    writing.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 3)     || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(9, 1)   || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(201710) || \
    defined(BUILD2_AUTOCONF_MACOS)
#  define HAVE_NEWLOCALE 1
#endif

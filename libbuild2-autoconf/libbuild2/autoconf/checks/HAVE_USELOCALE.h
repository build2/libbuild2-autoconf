// HAVE_USELOCALE : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_USELOCALE

/* Note: see also HAVE_NEWLOCALE. */

/* Since glibc 2.3, FreeBSD 9.1, OpenBSD 6.2, and Mac OS X (hard to tell but
 * based on the manpages available online it looks like Tiger at the latest).
 *
 * @@ TODO Update when NetBSD adds support for uselocale. newlocale at least
 *    is in CURRENT already.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 3)     || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(9, 1)   || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(201710) || \
    defined(BUILD2_AUTOCONF_MACOS)
#  define HAVE_USELOCALE 1
#endif

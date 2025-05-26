// HAVE_LSTAT : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_LSTAT

/* Check for the lstat() function.
 *
 * glibc 1.90, 4.2BSD and thus all BSD systems (including MacOS) since the
 * beginning, Solaris.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(1, 90) || \
    defined(__FreeBSD__)                || \
    defined(__NetBSD__)                 || \
    defined(__OpenBSD__)                || \
    defined(BUILD2_AUTOCONF_MACOS)      || \
    ((defined(__sun) && defined(__SVR4)) || defined(__sun__))
#  define HAVE_LSTAT 1
#endif

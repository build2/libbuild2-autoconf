// HAVE_MPROTECT : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_MPROTECT

/* Since glibc 2.27 and all versions of FreeBSD, OpenBSD, NetBSD, and Mac OS.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 27) || \
    defined(__FreeBSD__)                || \
    defined(__OpenBSD__)                || \
    defined(__NetBSD__)                 || \
    defined(BUILD2_AUTOCONF_MACOS)
#  define HAVE_MPROTECT 1
#endif

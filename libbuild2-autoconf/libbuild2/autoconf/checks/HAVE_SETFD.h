// HAVE_SETFD : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_SETFD

/* Since SVr4, 4.3BSD, POSIX.1-2001 (only Linux mentioned but assume all
 * because it's old & standardized),
 * glibc 1.90
 */
#if defined(__FreeBSD__)                || \
    defined(__OpenBSD__)                || \
    defined(__NetBSD__)                 || \
    defined(BUILD2_AUTOCONF_MACOS)      || \
    BUILD2_AUTOCONF_GLIBC_PREREQ(1, 90)
#  define HAVE_SETFD 1
#endif

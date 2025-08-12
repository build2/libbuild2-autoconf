// HAVE_TRUNC : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_TRUNC

// NOTE: keep consistent with HAVE_TRUNCF.

/* Check for the trunc() function.
 *
 * Available on Linux/glibc 2.1, FreeBSD 5.3, OpenBSD 4.0, NetBSD 4.0, MacOS
 * 10.2, Windows including MinGW.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 1)     || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(5, 3)   || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(200611) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(4, 0)    || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 2)    || \
    defined(_WIN32)
#  define HAVE_TRUNC 1
#endif

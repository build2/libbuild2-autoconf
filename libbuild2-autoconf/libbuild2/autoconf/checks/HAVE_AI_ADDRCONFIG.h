// HAVE_AI_ADDRCONFIG : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_AI_ADDRCONFIG

/* Since Linux/glibc 2.3.4, OpenBSD >=5.6, FreeBSD >=6.3, Mac OS, Windows.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 4)      || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(201411)  || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(6, 3)    || \
    defined(BUILD2_AUTOCONF_MACOS)          || \
    defined(_WIN32)
#  define HAVE_AI_ADDRCONFIG 1
#endif

// HAVE_SYS_STAT_H : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_SYS_STAT_H
/* Since 4.2BSD (~1983)
 */
#if defined(__linux__)              || \
    defined(__FreeBSD__)            || \
    defined(__OpenBSD__)            || \
    defined(__NetBSD__)             || \
    defined(BUILD2_AUTOCONF_MACOS)  || \
    defined(_WIN32)
#  define HAVE_SYS_STAT_H 1
#endif

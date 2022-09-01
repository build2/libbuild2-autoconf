// HAVE_ARPA_INET_H : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_ARPA_INET_H

/* Since BSD 4.2 (1983) */
#if defined(__FreeBSD__)            || \
    defined(__OpenBSD__)            || \
    defined(__NetBSD__)             || \
    defined(__GLIBC__)              || \
    defined(BUILD2_AUTOCONF_MACOS)
#  define HAVE_ARPA_INET_H 1
#endif

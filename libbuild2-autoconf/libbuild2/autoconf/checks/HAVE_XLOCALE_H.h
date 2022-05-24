// HAVE_XLOCALE_H : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_XLOCALE_H

#if BUILD2_AUTOCONF_FREEBSD_PREREQ(9, 1) || \
    defined(__APPLE__) && defined(__MACH__)
#  define HAVE_XLOCALE_H 1
#endif

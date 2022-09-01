// HAVE_FD_MASK : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_FD_MASK

/* Extremely little information, other than it being very old... */
#if defined(__FreeBSD__)            || \
    defined(__OpenBSD__)            || \
    defined(__NetBSD__)             || \
    defined(__GLIBC__)              || \
    defined(BUILD2_AUTOCONF_MACOS)
#  define HAVE_FD_MASK 1
#endif

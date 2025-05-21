// HAVE_FTRUNCATE : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_FTRUNCATE

/* This checks if ftruncate() is available, which truncates a file to a
 * specified length.
 */
#if defined(__GLIBC__)             || \
    defined(__FreeBSD__)           || \
    defined(__NetBSD__)            || \
    defined(__OpenBSD__)           || \
    defined(BUILD2_AUTOCONF_MACOS) || \
    defined(__MINGW32__)
#  define HAVE_FTRUNCATE 1
#endif

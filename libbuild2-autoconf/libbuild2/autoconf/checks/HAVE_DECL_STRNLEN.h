// HAVE_DECL_STRNLEN : BUILD2_AUTOCONF_LIBC_VERSION

#undef HAVE_DECL_STRNLEN

/* This checks for the declaration of the strnlen() function, which
 * calculates the length of a string up to a specified maximum number
 * of characters.
 * It is part of the POSIX standard but not universally available.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 10) || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(8, 0) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(6, 0) || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 7) || \
    defined(_WIN32) || \
    defined(__MINGW32__) || \
    defined(__CYGWIN__)
#  define HAVE_DECL_STRNLEN 1
#endif

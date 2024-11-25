// HAVE_DECL_STRNCASECMP : BUILD2_AUTOCONF_LIBC_VERSION

#undef HAVE_DECL_STRNCASECMP

/* This checks for the declaration of the strncasecmp() function,
 * which performs a case-insensitive comparison of two strings
 * up to a specified length. It is part of POSIX and widely
 * available on Unix-like systems.
 */
#if defined(__linux__) || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(1, 0) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 0) || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199706) || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 0)
#  define HAVE_DECL_STRNCASECMP 1
#endif

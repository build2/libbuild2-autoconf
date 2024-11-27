// HAVE_DECL_STRICMP : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_DECL_STRICMP

/* Indicates the declaration of stricmp(), which
 * performs case-insensitive string comparison.
 * Available on Windows and MinGW.
 */
#if defined(__linux__) || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(1, 0) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 0) || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199610) || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 0) || \
    defined(_WIN32) || \
    defined(__MINGW32__) || \
    defined(__CYGWIN__)
#  define HAVE_DECL_STRICMP 1
#endif

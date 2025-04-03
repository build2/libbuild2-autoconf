// HAVE_DECL_STRSEP : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_DECL_STRSEP

/* Checks for the declaration of the strsep() function,
 * which tokenizes strings by replacing delimiters with \\0.
 */
#if defined(__linux__) || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(1, 0) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 0) || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199610) || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 0)
#  define HAVE_DECL_STRSEP 1
#endif

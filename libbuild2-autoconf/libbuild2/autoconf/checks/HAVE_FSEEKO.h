// HAVE_FSEEKO : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_FSEEKO

/* This checks for fseeko(), which is a large-file-aware
 * alternative to fseek().
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 1)    || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(3, 0)  || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(2, 0)   || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 0)   || \
    defined(__CYGWIN__)                   || \
    defined(__MINGW32__)                  || \
    (defined(__sun) && defined(__SVR4))   // Solaris
#  define HAVE_FSEEKO 1
#endif

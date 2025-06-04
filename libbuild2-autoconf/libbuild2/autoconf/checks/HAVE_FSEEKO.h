// HAVE_FSEEKO : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_FSEEKO

/* Check for the fseeko() function which is a large-file-aware alternative to
 * fseek().
 *
 * Since OpenBSD 2.7 (June 2000). Not available on Windows (except Mingw-w64).
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 1)     || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(3, 2)   || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(200006) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 6)    || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 0)    || \
    defined(__CYGWIN__)                    || \
    defined(__MINGW32__)                   || \
    (defined(__sun) && defined(__SVR4))   /* Solaris */
#  define HAVE_FSEEKO 1
#endif

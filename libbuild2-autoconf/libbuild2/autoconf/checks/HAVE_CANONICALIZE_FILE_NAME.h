// HAVE_CANONICALIZE_FILE_NAME : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_CANONICALIZE_FILE_NAME

/* Checks if the canonicalize_file_name function for getting the
 * absolute path resolving symlinks is available.
 * Since glibc 2.3.3, not available on BSDs, Windows, Mingw-w64, MacOS, Solaris */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 3)
#  define HAVE_CANONICALIZE_FILE_NAME 1
#endif

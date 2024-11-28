// HAVE_MEMPCPY : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_MEMPCPY

/* This checks for mempcpy() availability, which copies memory and
 * returns a pointer to the end of the copied data. It's a GNU extension.
 */
#if defined(__GNUC__) && \
    BUILD2_AUTOCONF_GLIBC_PREREQ(2, 2) || \
    BUILD2_AUTOCONF_MINGW_PREREQ(1, 0) || \
    defined(__CYGWIN__)
#  define HAVE_MEMPCPY 1
#endif

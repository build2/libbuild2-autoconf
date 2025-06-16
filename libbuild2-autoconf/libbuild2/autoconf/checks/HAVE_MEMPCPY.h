// HAVE_MEMPCPY : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_MEMPCPY

/* Check for the mempcpy() function which copies memory and returns a pointer
 * to the end of the copied data.
 *
 * This is a GNU extension. Not available on Windows (except Mingw-w64).
 *
 * @@ TODO mempcpy() is present in NetBSD-current but not yet released so keep
 *    an eye on that.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 1)    || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(13, 1) || \
    BUILD2_AUTOCONF_MINGW_PREREQ(2, 0)    || \
    defined(__CYGWIN__)
#  define HAVE_MEMPCPY 1
#endif

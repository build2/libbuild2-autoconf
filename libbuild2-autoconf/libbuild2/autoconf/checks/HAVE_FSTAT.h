// HAVE_FSTAT : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_FSTAT

/* Check for the fstat() function which retrieves file information using a
 * file descriptor.
 *
 * The Windows equivalent is _fstat*() (see the HAVE__FSTAT* checks).
 *
 * Mingw-w64 supports this function by default. It does however hide the
 * declaration if NO_OLDNAMES is defined, but this seems unlikely given that
 * this would also disable many other common POSIX functions.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 4) || \
    defined(__APPLE__)                 || \
    defined(__FreeBSD__)               || \
    defined(__NetBSD__)                || \
    defined(__OpenBSD__)               || \
    defined(__MINGW32__)
#  define HAVE_FSTAT 1
#endif

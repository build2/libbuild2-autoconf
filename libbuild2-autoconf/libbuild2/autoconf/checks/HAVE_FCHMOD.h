// HAVE_FCHMOD : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_FCHMOD

/* Check for the fchmod() function.
 *
 * Available since glibc 2.10 but is only enabled if certain macros are
 * defined (see chmod(2) for details). For now we only cover 2.16 and up and
 * _POSIX_C_SOURCE. Assume available in all BSD and Apple OS versions we care
 * to target (reportedly available since 4.2BSD). Not available on Windows
 * (including MinGW).
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 24)
#  if defined(_POSIX_C_SOURCE) && _POSIX_C_SOURCE >= 199309L
#    define HAVE_FCHMOD 1
#  endif
#elif BUILD2_AUTOCONF_GLIBC_PREREQ(2, 16)
#  if defined(_POSIX_C_SOURCE)
#    define HAVE_FCHMOD 1
#  endif
#elif defined(__FreeBSD__) || \
      defined(__OpenBSD__) || \
      defined(__NetBSD__)  || \
      defined(__APPLE__)
#  define HAVE_FCHMOD 1
#endif

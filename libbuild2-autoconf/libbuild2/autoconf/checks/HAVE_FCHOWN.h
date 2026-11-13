// HAVE_FCHOWN : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_FCHOWN

/* Check for the fchown() function.
 *
 * Available since glibc 2.12 but is only enabled if certain macros are
 * defined (see chown(2) for details). For now we only cover _POSIX_C_SOURCE.
 * Assume available in all BSD and Apple OS versions we care to target
 * (reportedly available since 4.2BSD). Not available on Windows (including
 * MinGW).
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 12)
#  if defined(_POSIX_C_SOURCE) && _POSIX_C_SOURCE >= 200809L
#    define HAVE_FCHOWN 1
#  endif
#elif defined(__FreeBSD__) || \
      defined(__OpenBSD__) || \
      defined(__NetBSD__)  || \
      defined(__APPLE__)
#  define HAVE_FCHOWN 1
#endif

// HAVE__GMTIME32 : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE__GMTIME32

/* Win32
 */
#if defined(_WIN32)
#  define HAVE__GMTIME32 1
#endif

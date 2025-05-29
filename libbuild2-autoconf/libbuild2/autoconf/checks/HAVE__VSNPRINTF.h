// HAVE__VSNPRINTF : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE__VSNPRINTF

/* This checks for the snprintf() function, which safely
 * formats strings into a buffer.
 * It’s part of the C99 standard and widely available.
 */
#if defined(_WIN32) || defined(__MINGW32__)
#  define HAVE__VSNPRINTF 1
#endif

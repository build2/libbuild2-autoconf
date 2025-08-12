// HAVE__VSNPRINTF

#undef HAVE__VSNPRINTF

/* Check for the _vsnprintf() function.
 * _vsnprintf() is a Microsoft-specific function that safely formats strings
 * into a buffer with a size limit.
 *
 * Available on Windows including MinGW. Not available on Linux/glibc or MacOS.
 */
#if defined(_WIN32)
#  define HAVE__VSNPRINTF 1
#endif

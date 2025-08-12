// HAVE__STATI64

#undef HAVE__STATI64

/* Check for the _stati64() function.
 * _stati64() is a Microsoft-specific function that retrieves file status
 * information using a 64-bit structure for large file support.
 *
 * Available on Windows including MinGW. Not available on Linux/glibc or MacOS.
 */
#if defined(_WIN32)
#  define HAVE__STATI64 1
#endif

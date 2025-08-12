// HAVE__FSTATI64

#undef HAVE__FSTATI64

/* Check for the _fstati64() function.
 * _fstati64() is a Microsoft-specific function that retrieves file status
 * information for a file descriptor using a 64-bit structure.
 *
 * Available on Windows including MinGW. Not available on Linux/glibc or MacOS.
 */
#if defined(_WIN32)
#  define HAVE__FSTATI64 1
#endif

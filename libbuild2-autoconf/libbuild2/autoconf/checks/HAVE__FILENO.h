// HAVE__FILENO

#undef HAVE__FILENO

/* Check for the _fileno() function.
 * _fileno() is a Microsoft-specific function that retrieves the file
 * descriptor associated with a FILE stream.
 *
 * Available on Windows including MinGW. Not available on Linux/glibc or MacOS.
 */
#if defined(_WIN32)
#  define HAVE__FILENO 1
#endif

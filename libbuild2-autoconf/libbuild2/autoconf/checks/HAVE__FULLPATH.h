// HAVE__FULLPATH

#undef HAVE__FULLPATH

/* Check for the _fullpath() function.
 * _fullpath() is a Microsoft-specific function that converts a relative file
 * path to an absolute path.
 *
 * Available on Windows including MinGW. Not available on Linux/glibc or MacOS.
 */
#if defined(_WIN32)
#  define HAVE__FULLPATH 1
#endif

// HAVE__CHSIZE

#undef HAVE__CHSIZE

/* Check for the _chsize() function.
 * _chsize() is a Microsoft-specific function that changes the size of a file.
 *
 * Available on Windows including MinGW. Not available on Linux/glibc or MacOS.
 */
#if defined(_WIN32)
#  define HAVE__CHSIZE 1
#endif

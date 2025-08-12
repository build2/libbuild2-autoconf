// HAVE__CHSIZE_S

#undef HAVE__CHSIZE_S

/* Check for the _chsize_s() function.
 * _chsize_s() is a Microsoft-specific function that changes the size of a
 * file.
 *
 * Available on Windows including MinGW. Not available on Linux/glibc or MacOS.
 */
#if defined(_WIN32)
#  define HAVE__CHSIZE_S 1
#endif

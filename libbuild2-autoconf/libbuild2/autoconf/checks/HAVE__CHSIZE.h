// HAVE__CHSIZE

#undef HAVE__CHSIZE

/* Checks for the _chsize() function, which changes the size of a file.
 * This is a Microsoft-specific function.
 */
#if defined(_WIN32)
#  define HAVE__CHSIZE 1
#endif

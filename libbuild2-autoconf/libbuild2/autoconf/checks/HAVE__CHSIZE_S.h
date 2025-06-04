// HAVE__CHSIZE_S

#undef HAVE__CHSIZE_S

/* Checks for the _chsize() function, which changes the size of a file.
 * This is a Microsoft-specific function.
 */
#if defined(_WIN32)
#  define HAVE__CHSIZE_S 1
#endif

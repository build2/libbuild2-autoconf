// HAVE_MAPVIEWOFFILE

#undef HAVE_MAPVIEWOFFILE

/* Check for the MapViewOfFile() function.
 *
 * Available on Windows including MinGW. Not available on Linux/glibc or MacOS.
 */
#if defined(_WIN32)
#  define HAVE_MAPVIEWOFFILE 1
#endif

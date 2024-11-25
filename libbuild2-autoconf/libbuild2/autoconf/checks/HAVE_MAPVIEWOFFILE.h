// HAVE_MAPVIEWOFFILE

#undef HAVE_MAPVIEWOFFILE

/* Presence of MapViewOfFile() function.
 * Supported on Windows
 */
#if defined(_WIN32)
#  define HAVE_MAPVIEWOFFILE 1
#endif

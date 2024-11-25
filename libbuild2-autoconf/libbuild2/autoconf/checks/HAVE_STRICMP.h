// HAVE_STRICMP

#undef HAVE_STRICMP

/* This checks for the availability of the stricmp() function,
 * a case-insensitive string comparison function. It is not part
 * of the standard C library but is available on Windows platforms
 * and some other environments under various names.
 */
#if defined(_WIN32) || \
    defined(__MINGW32__) || \
    defined(__CYGWIN__)
#  define HAVE_STRICMP 1
#endif

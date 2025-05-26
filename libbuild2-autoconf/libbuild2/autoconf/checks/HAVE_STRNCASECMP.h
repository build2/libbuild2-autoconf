// HAVE_STRNCASECMP : HAVE_STRCASECMP

#undef HAVE_STRNCASECMP

/* Check for the strncasecmp() function which performs a case-insensitive
 * comparison of two strings up to a specified number of characters.
 *
 * It is a POSIX function. Not available on Windows (except Mingw-w64).
 *
 * strncasecmp() and strcasecmp() were added at the same time in all of the
 * systems I checked (see HAVE_STRCASECMP.h).
 */
#ifdef HAVE_STRCASECMP
#  define HAVE_STRNCASECMP 1
#endif

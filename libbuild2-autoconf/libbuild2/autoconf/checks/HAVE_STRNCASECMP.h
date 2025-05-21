// HAVE_STRNCASECMP : HAVE_STRCASECMP

#undef HAVE_STRNCASECMP

/* This checks for the availability of the strncasecmp() function,
 * which performs a case-insensitive comparison of two strings up
 * to a specified number of characters.
 * It is part of the POSIX standard and is widely available on Unix-like systems.
 *
 * strncasecmp() and strcasecmp() were added at the same time in all of the
 * systems I checked (see HAVE_STRCASECMP.h).
 */
#ifdef HAVE_STRCASECMP
#  define HAVE_STRNCASECMP 1
#endif

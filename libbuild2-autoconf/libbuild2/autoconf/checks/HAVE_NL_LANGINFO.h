// HAVE_NL_LANGINFO

#undef HAVE_NL_LANGINFO

/* Check for the ln_langinfo() function.
 *
 * Assume available everywhere except Windows (not even MinGW). See also
 * HAVE_LANGINFO_H.
 */
#ifndef _WIN32
#  define HAVE_NL_LANGINFO 1
#endif

// HAVE_LANGINFO_H

#undef HAVE_LANGINFO_H

/* Check for the langinfo.h header.
 *
 * Assume available everywhere except Windows (not even MinGW). See also
 * HAVE_NL_LANGINFO.
 */
#ifndef _WIN32
#  define HAVE_LANGINFO_H 1
#endif

// HAVE_DIRECT_H

#undef HAVE_DIRECT_H

/* Check for the <direct.h> header.
 *
 * Available on Windows including MinGW. Not available on Linux/glibc or MacOS.
 */
#if defined(_WIN32)
#  define HAVE_DIRECT_H 1
#endif

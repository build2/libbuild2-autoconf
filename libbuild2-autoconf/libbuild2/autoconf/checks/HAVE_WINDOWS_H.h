// HAVE_WINDOWS_H

#undef HAVE_WINDOWS_H

/* Check for the <windows.h> header.
 *
 * Available on Windows including MinGW. Not available on Linux/glibc or MacOS.
 */
#if defined(_WIN32)
#  define HAVE_WINDOWS_H 1
#endif

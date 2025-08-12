// HAVE_WINSOCK2_H

#undef HAVE_WINSOCK2_H

/* Check for the <winsock2.h> header.
 *
 * Available on Windows including MinGW. Not available on Linux/glibc or MacOS.
 */
#if defined(_WIN32)
#  define HAVE_WINSOCK2_H 1
#endif

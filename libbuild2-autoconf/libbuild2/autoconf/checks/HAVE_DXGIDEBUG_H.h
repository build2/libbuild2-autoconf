// HAVE_DXGIDEBUG_H

#undef HAVE_DXGIDEBUG_H

/* Check for the <dxgidebug.h> header.
 * dxgidebug.h provides APIs for debugging DirectX applications.
 *
 * Available on Windows including MinGW. Not available on Linux/glibc or MacOS.
 */
#if defined(_WIN32)
#  define HAVE_DXGIDEBUG_H 1
#endif

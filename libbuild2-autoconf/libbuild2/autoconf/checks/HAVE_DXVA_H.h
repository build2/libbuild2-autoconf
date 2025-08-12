// HAVE_DXVA_H

#undef HAVE_DXVA_H

/* Check for the <dxva.h> header.
 * dxva.h provides APIs for DirectX Video Acceleration on Windows.
 *
 * Available on Windows including MinGW. Not available on Linux/glibc or MacOS.
 */
#if defined(_WIN32)
#  define HAVE_DXVA_H 1
#endif

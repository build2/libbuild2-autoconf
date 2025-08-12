// HAVE_UWP

#undef HAVE_UWP

/* Check for Universal Windows Platform (UWP) support.
 *
 * Available on Windows since Windows 8. Not available on Linux/glibc or MacOS.
 */
#if defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_APP)
#  define HAVE_UWP 1
#endif

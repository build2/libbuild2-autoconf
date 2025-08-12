// HAVE_WINRT

#undef HAVE_WINRT

/* Check for the presence of Windows Runtime (WinRT) APIs.
 *
 * Available on Windows including MinGW. Not available on Linux/glibc or MacOS.
 */
#ifdef __cplusplus_winrt
#  define HAVE_WINRT 1
#endif

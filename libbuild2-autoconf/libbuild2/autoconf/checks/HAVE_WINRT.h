// HAVE_WINRT

#undef HAVE_WINRT

/* Presence of Windows Runtime (WinRT) APIs, used for building
 * Universal Windows Platform (UWP) applications.
 */
#ifdef __cplusplus_winrt
#  define HAVE_WINRT 1
#endif

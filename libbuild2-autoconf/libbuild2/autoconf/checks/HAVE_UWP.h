// HAVE_UWP

#undef HAVE_UWP

/* Presence of Universal Windows Platform (UWP) support.
 * Since Windows 8
 */
#if defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_APP)
#  define HAVE_UWP 1
#endif

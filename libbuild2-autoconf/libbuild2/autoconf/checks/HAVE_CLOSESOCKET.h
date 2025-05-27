// HAVE_CLOSESOCKET

#undef HAVE_CLOSESOCKET

/* Check for the closesocket() function.
 *
 * Windows and MinGW.
 */
#if defined(_WIN32) || \
    defined(__MINGW32__)
#  define HAVE_CLOSESOCKET 1
#endif

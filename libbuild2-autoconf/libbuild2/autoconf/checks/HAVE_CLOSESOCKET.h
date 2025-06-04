// HAVE_CLOSESOCKET

#undef HAVE_CLOSESOCKET

/* Windows, Mingw
 */
#if defined(_WIN32) || \
    defined(__MINGW32__)
#  define HAVE_CLOSESOCKET 1
#endif

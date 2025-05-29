// HAVE_WINSOCK2_H

#undef HAVE_WINSOCK2_H

/* Windows, Mingw
 */
#if defined(_WIN32) || \
    defined(__MINGW32__)
#  define HAVE_WINSOCK2_H 1
#endif

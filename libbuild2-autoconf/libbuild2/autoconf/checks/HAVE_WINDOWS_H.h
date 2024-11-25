// HAVE_WINDOWS_H

#undef HAVE_WINDOWS_H

/* Windows, Mingw
 */
#if defined(_WIN32) || \
    defined(__MINGW32__)
#  define HAVE_WINDOWS_H 1
#endif

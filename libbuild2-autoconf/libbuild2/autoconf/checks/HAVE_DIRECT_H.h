// HAVE_DIRECT_H

#undef HAVE_DIRECT_H

/* Windows, Mingw
 */
#if defined(_WIN32) || \
    defined(__MINGW32__)
#  define HAVE_DIRECT_H 1
#endif

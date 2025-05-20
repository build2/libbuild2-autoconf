// HAVE_DXVA_H

#undef HAVE_DXVA_H

/* Windows, Mingw
 */
#if defined(_WIN32) || \
    defined(__MINGW32__)
#  define HAVE_DXVA_H 1
#endif

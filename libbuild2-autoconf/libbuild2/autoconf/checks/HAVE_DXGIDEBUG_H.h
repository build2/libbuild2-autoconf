// HAVE_DXGIDEBUG_H

#undef HAVE_DXGIDEBUG_H

/* Windows, Mingw
 */
#if defined(_WIN32) || \
    defined(__MINGW32__)
#  define HAVE_DXGIDEBUG_H 1
#endif

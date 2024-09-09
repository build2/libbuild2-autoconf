// HAVE_MALLOC_H

#undef HAVE_MALLOC_H

/* Presence of malloc.h.
 * Supported on Linux (deprecated since glibc 2.0), Windows * Mingw
 */
#if (defined(__GLIBC__) && __GLIBC__ < 2) || \
    defined(_WIN32) || \
    defined(__MINGW32__)
#  define HAVE_MALLOC_H 1
#endif

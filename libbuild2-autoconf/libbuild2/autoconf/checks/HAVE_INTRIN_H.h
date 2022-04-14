// HAVE_INTRIN_H

#undef HAVE_INTRIN_H

/* Windows only: MSVC, MinGW-W64, and Clang.
 */
#if defined(_WIN32) && \
    (defined(_MSV_VER) || defined(__MINGW32__) || defined(__clang__))
#  define HAVE_INTRIN_H 1
#endif

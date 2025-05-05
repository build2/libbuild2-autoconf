// HAVE_SSE4

#undef HAVE_SSE4

/* Presence of SSE4 (Streaming SIMD Extensions 4)
 * instructions, which include SSE4.1 and SSE4.2.
 * This code is based on HAVE_SSE4_1 and:
 * https://code.qt.io/cgit/qt/qtbase.git/tree/src/corelib/global/qsimd.h.
 */
#ifdef _MSC_VER
#  ifdef __AVX__
#    define HAVE_SSE4 1
#  endif
#elif defined(__SSE4_1__) || defined(__SSE4_2__)
#  define HAVE_SSE4 1
#endif

// HAVE_SSE3

#undef HAVE_SSE3

/* GCC, Clang: -msse3
 *
 * MSVC: /arch:{AVX,AVX2,AVX512}
 *
 * This code is based on
 * https://code.qt.io/cgit/qt/qtbase.git/tree/src/corelib/global/qsimd.h.
 */
#ifdef _MSC_VER
#  ifdef __AVX__
#    define HAVE_SSE3 1
#  endif
#else
#  ifdef __SSE3__
#    define HAVE_SSE3 1
#  endif
#endif

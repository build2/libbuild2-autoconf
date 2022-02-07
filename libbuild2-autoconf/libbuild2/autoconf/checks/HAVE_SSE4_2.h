// HAVE_SSE4_2

#undef HAVE_SSE4_2

/* GCC, Clang: -msse4.2
 *
 * MSVC: /arch:{AVX,AVX2,AVX512}
 *
 * Supported since Intel's Nehalem (2008), AMD's Bulldozer (2011), and GCC 4.3
 * (2008).
 *
 * This code is based on
 * https://code.qt.io/cgit/qt/qtbase.git/tree/src/corelib/global/qsimd.h.
 */
#ifdef _MSC_VER
#  ifdef __AVX__
#    define HAVE_SSE4_2 1
#  endif
#else
#  ifdef __SSE4_2__
#    define HAVE_SSE4_2 1
#  endif
#endif

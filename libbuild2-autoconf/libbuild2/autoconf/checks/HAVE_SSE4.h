// HAVE_SSE4

#undef HAVE_SSE4

/* Check for SSE4 support.
 * SSE4 is a SIMD extension for x86 processors, including SSE4.1 and SSE4.2.
 * This code is based on
 * https://code.qt.io/cgit/qt/qtbase.git/tree/src/corelib/global/qsimd.h.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 */
#ifdef _MSC_VER
#  ifdef __AVX__
#    define HAVE_SSE4 1
#  endif
#elif defined(__SSE4_1__) || \
      defined(__SSE4_2__)
#  define HAVE_SSE4 1
#endif

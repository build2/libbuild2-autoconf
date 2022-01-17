// HAVE_SSSE3

#undef HAVE_SSSE3

/* GCC, Clang: -mssse3
 *
 * MSVC: /arch:{AVX,AVX2,AVX512}
 *
 * This code is based on
 * https://code.qt.io/cgit/qt/qtbase.git/tree/src/corelib/global/qsimd.h.
 */
#ifdef _MSC_VER
#  ifdef __AVX__
#    define HAVE_SSSE3 1
#  endif
#else
#  ifdef __SSSE3__
#    define HAVE_SSSE3 1
#  endif
#endif

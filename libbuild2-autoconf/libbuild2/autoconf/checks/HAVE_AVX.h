// HAVE_AVX

#undef HAVE_AVX

/* GCC, Clang: -mavx
 *
 * MSVC: /arch:{AVX,AVX2,AVX512}
 *
 * This code is based on
 * https://code.qt.io/cgit/qt/qtbase.git/tree/src/corelib/global/qsimd.h.
 */
#ifdef __AVX__
#  define HAVE_AVX 1
#endif

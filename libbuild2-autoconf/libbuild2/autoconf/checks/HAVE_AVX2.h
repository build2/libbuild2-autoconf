// HAVE_AVX2

#undef HAVE_AVX2

/* GCC, Clang: -mavx2
 *
 * MSVC: /arch:{AVX2,AVX512}
 *
 * This code is based on
 * https://code.qt.io/cgit/qt/qtbase.git/tree/src/corelib/global/qsimd.h.
 */
#ifdef __AVX2__
#  define HAVE_AVX2 1
#endif

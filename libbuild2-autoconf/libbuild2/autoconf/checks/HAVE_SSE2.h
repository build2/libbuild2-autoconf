// HAVE_SSE2

#undef HAVE_SSE2

/* GCC, Clang: -msse2
 *
 * MSVC (x86):    /arch:{SSE2,AVX,AVX2,AVX512}
 * MSVC (X86-64): Always enabled
 *
 * This code is based on
 * https://code.qt.io/cgit/qt/qtbase.git/tree/src/corelib/global/qsimd.h.
 */
#ifdef _MSC_VER
#  if defined(_M_X64) || (defined(_M_IX86_FP) && _M_IX86_FP >= 2)
#    define HAVE_SSE2 1
#  endif
#else
#  ifdef __SSE2__
#    define HAVE_SSE2 1
#  endif
#endif

// HAVE_RDRND

#undef HAVE_RDRND

/* GCC, Clang: -mrdrnd
 *
 * MSVC: No controlling compiler option nor indicating macro. The
 *       documentation murkily says it's always enabled on Intel and only
 *       Intel processors; see:
 *       https://docs.microsoft.com/en-us/cpp/intrinsics/x86-intrinsics-list
 *       https://docs.microsoft.com/en-us/cpp/intrinsics/x64-amd64-intrinsics-list)
 *
 *       According to Qt, all processors that support AVX2 support RDRND so
 *       follow their lead by assuming it's available if AVX2 is.
 *
 *       Note that RDRND intrinsics were added to Visual C++ 2015 according to
 *       Wikipedia.
 */
#if defined(__RDRND__) || (defined(_MSC_VER) && defined(__AVX2__))
#  define HAVE_RDRND 1
#endif

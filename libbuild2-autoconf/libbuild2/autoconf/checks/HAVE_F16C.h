// HAVE_F16C

#undef HAVE_F16C

/* GCC, Clang: -mf16c
 *
 * MSVC: No controlling compiler option nor indicating macro. The
 *       documentation murkily says it's always enabled on Intel and only
 *       Intel processors; see:
 *       https://docs.microsoft.com/en-us/cpp/intrinsics/x86-intrinsics-list
 *       https://docs.microsoft.com/en-us/cpp/intrinsics/x64-amd64-intrinsics-list)
 *
 *       Instead we make use of the fact that all processors that support AVX2
 *       also support F16C.
 *
 * Supported since Intel's Ivy Bridge (2012) and AMD's Bulldozer (2011). Added
 * to GCC 4.6.4 (2013) at the latest.
 */
#ifdef _MSC_VER
#  ifdef __AVX2__
#    define HAVE_F16C 1
#  endif
#else
#  ifdef __F16C__
#    define HAVE_F16C 1
#  endif
#endif

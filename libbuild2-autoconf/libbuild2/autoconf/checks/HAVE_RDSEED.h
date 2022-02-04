// HAVE_RDSEED

#undef HAVE_RDSEED

/* GCC, Clang: -mrdseed
 *
 * MSVC: No controlling compiler option nor indicating macro. The
 *       documentation murkily says it's always enabled on Intel and only
 *       Intel processors; see:
 *       https://docs.microsoft.com/en-us/cpp/intrinsics/x86-intrinsics-list
 *       https://docs.microsoft.com/en-us/cpp/intrinsics/x64-amd64-intrinsics-list)
 */
#ifdef __RDSEED__
#  define HAVE_RDSEED 1
#endif

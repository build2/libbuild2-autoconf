// HAVE_AES

#undef HAVE_AES

/* GCC, Clang: -maes
 *
 * MSVC: No controlling compiler option nor indicating macro. The
 *       documentation murkily says it's always enabled on Intel and only
 *       Intel processors; see:
 *       https://docs.microsoft.com/en-us/cpp/intrinsics/x86-intrinsics-list
 *       https://docs.microsoft.com/en-us/cpp/intrinsics/x64-amd64-intrinsics-list)
 *
 * The AES-NI instructions which are widely supported in CPUs (since 2009 for
 * Intel; also `latest` ARM and SPARC processors) and most modern compilers
 * (according to Wikipedia). First added to GCC 4.4.7 (2012).
 */
#ifdef __AES__
#  define HAVE_AES 1
#endif

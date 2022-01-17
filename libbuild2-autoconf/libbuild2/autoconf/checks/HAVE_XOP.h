// HAVE_XOP

#undef HAVE_XOP

/* GCC, Clang: -mxop
 *
 * MSVC: No controlling compiler option nor indicating macro. The
 *       documnetation is murkily says it's always enabled on AMD and only AMD
 *       processors; see:
 *       https://docs.microsoft.com/en-us/cpp/intrinsics/x86-intrinsics-list
 *       https://docs.microsoft.com/en-us/cpp/intrinsics/x64-amd64-intrinsics-list)
 */
#ifdef __XOP__
#  define HAVE_XOP 1
#endif

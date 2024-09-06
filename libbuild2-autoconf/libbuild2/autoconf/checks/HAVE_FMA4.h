// HAVE_FMA4

#undef HAVE_FMA4

/* GCC, Clang: -mfma4
 *
 * MSVC: /arch:AVX2
 */
#ifdef __FMA4__
#  define HAVE_FMA4 1
#endif

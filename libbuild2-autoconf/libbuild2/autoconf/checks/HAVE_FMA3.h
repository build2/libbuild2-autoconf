// HAVE_FMA3

#undef HAVE_FMA3

/* GCC, Clang: -mfma
 *
 * MSVC: /arch:AVX2
 */
#ifdef __FMA__
#  define HAVE_FMA3 1
#endif

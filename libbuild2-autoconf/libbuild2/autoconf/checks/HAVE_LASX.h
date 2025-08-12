// HAVE_LASX

#undef HAVE_LASX

/* Check for LASX support.
 * LASX is a LoongArch SIMD extension for advanced vector operations.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 * Supported by GCC, Clang.
 */
#ifdef __loongarch_asx
#  define HAVE_LASX 1
#endif

// HAVE_LSX

#undef HAVE_LSX

/* Check for LSX support.
 * LSX is a LoongArch SIMD extension for vector operations.
 *
 * Available on Linux/glibc. Not available on MacOS or Windows including MinGW.
 * Supported by GCC, Clang.
 */
#ifdef __loongarch_sx
#  define HAVE_LSX 1
#endif

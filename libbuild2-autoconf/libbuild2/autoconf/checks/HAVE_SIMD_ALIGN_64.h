// HAVE_SIMD_ALIGN_64

#undef HAVE_SIMD_ALIGN_64

/* Check for 64-byte SIMD alignment support.
 * 64-byte alignment is required for AVX-512 SIMD operations.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 */
#if defined(__AVX512F__)
#  define HAVE_SIMD_ALIGN_64 1
#endif
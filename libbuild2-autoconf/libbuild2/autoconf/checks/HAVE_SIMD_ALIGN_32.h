// HAVE_SIMD_ALIGN_32

#undef HAVE_SIMD_ALIGN_32

/* Check for 32-byte SIMD alignment support.
 * 32-byte alignment is required for AVX SIMD operations.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 */
#if defined(__AVX__)
#  define HAVE_SIMD_ALIGN_32 1
#endif
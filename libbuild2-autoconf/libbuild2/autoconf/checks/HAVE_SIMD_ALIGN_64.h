// HAVE_SIMD_ALIGN_64

#undef HAVE_SIMD_ALIGN_64

/* Presence of 64-byte SIMD alignment, required for AVX-512.
 */
#if defined(__AVX512F__)
#  define HAVE_SIMD_ALIGN_64 1
#endif

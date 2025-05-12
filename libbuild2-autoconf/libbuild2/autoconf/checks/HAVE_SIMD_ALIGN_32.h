// HAVE_SIMD_ALIGN_32

#undef HAVE_SIMD_ALIGN_32

/* Presence of 32-byte SIMD alignment, required for AVX.
 */
#if defined(__AVX__)
#  define HAVE_SIMD_ALIGN_32 1
#endif

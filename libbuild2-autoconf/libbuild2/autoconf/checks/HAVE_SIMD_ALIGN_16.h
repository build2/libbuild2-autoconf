// HAVE_SIMD_ALIGN_16

#undef HAVE_SIMD_ALIGN_16

/* Presence of 16-byte SIMD alignment,
 * typically required for SSE and NEON.
 */
#if defined(__SSE__) || defined(__ARM_NEON) || defined(__ARM_NEON__)
#  define HAVE_SIMD_ALIGN_16 1
#endif

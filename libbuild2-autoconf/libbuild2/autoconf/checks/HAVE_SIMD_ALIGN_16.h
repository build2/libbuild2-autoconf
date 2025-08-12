// HAVE_SIMD_ALIGN_16

#undef HAVE_SIMD_ALIGN_16

/* Check for 16-byte SIMD alignment support.
 * 16-byte alignment is required for SSE and NEON SIMD operations.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 */
#if defined(__SSE__)      || \
    defined(__ARM_NEON)   || \
    defined(__ARM_NEON__) || \
    (defined(_WIN32) && (defined(_M_IX86) || defined(_M_X64)))
#  define HAVE_SIMD_ALIGN_16 1
#endif

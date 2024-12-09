// HAVE_SIMD_ALIGN_16

#undef HAVE_SIMD_ALIGN_16

/* Presence of 16-byte SIMD alignment,
 * typically required for SSE and NEON.
 * WIN32: Check for _M_IX86 or _M_X64 and SSE support.
 */
#if defined(__SSE__) || defined(__ARM_NEON) || defined(__ARM_NEON__) || \
    (defined(_WIN32) && (defined(_M_IX86) || defined(_M_X64)))
#  define HAVE_SIMD_ALIGN_16 1
#endif

// HAVE_LOCAL_ALIGNED

#undef HAVE_LOCAL_ALIGNED

/* Check for alignment attributes support.
 * Alignment attributes allow specifying memory alignment for variables or
 * structures in supported compilers.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 * Available on x86 with SSE or AVX, ARM with NEON, PowerPC with AltiVec.
 * Supported by GCC and MSVC.
 */
#if (defined(__SSE__)      || \
     defined(__AVX__)      || \
     defined(__ARM_NEON__) || \
     defined(__ALTIVEC__)) && \
    (defined(__GNUC__) || defined(_MSC_VER))
#  define HAVE_LOCAL_ALIGNED 1
#endif

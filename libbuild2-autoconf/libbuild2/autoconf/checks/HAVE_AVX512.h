// HAVE_AVX512

#undef HAVE_AVX512

/* Check for AVX-512 support.
 * AVX-512 is an extension to x86 instruction set for advanced vector
 * processing.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 * Supported by GCC with -march=knl or -march=skylake-avx512, MSVC with
 * /arch:AVX512.
 */
#if defined(__AVX512CD__) || \
    defined(__AVX512ER__) || \
    defined(__AVX512F__)  || \
    defined(__AVX512PF__) || \
    defined(__AVX512BW__) || \
    defined(__AVX512DQ__) || \
    defined(__AVX512VL__)
#  define HAVE_AVX512 1
#endif

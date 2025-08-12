// HAVE_AVX512ICL

#undef HAVE_AVX512ICL

/* Check for AVX-512 ICL extensions support.
 * AVX-512 ICL extensions include additional instructions for matrix
 * multiplication and vector operations.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 * Supported by GCC with -m avx512vbmi, avx512vbmi2, avx512vnni, avx512bf16,
 * avx512fp16, MSVC with /arch:AVX512.
 */
#if defined(__AVX512VBMI__) || \
    defined(__AVX512VNNI__)
#  define HAVE_AVX512ICL 1
#endif

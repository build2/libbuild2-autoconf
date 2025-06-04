// HAVE_AVX512ICL

#undef HAVE_AVX512ICL

/* GCC, Clang: -m={avx512vbmi, avx512vbmi2, avx512vnni, avx512bf16, avx512fp16}
 *
 * MSVC: /arch:AVX512
 *
 * Note: This refers to additional AVX-512 extensions that were introduced starting with Ice Lake (ICL)
 */

#if defined(__AVX512VBMI__) || \
    defined(__AVX512VNNI__)
#  define HAVE_AVX512ICL 1
#endif

// HAVE_AVX512

#undef HAVE_AVX512

/* GCC, Clang: -march={knl,skylake-avx512, ...}
 *
 * MSVC: /arch:AVX512
 *
 * This code is based on
 * * https://www.intel.com/content/www/us/en/docs/dpcpp-cpp-compiler/developer-guide-reference/2023-1/additional-predefined-macros.html
 * * https://learn.microsoft.com/en-us/cpp/preprocessor/predefined-macros?view=msvc-170
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

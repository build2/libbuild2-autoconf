// HAVE_FMA3

#undef HAVE_FMA3

/* GCC, Clang: -mfma
 *
 * MSVC: /arch:AVX2
 */
#if defined(__FMA__) || \
    (defined(_WIN32) && defined(__AVX2__))
#  define HAVE_FMA3 1
#endif

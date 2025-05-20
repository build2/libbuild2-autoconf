// HAVE_FMA4

#undef HAVE_FMA4

/* GCC, Clang: -mfma4
 *
 * MSVC: /arch:AVX2
 */
#if defined(__FMA4__) || \
    (defined(_WIN32) && defined(__AVX2__))
#  define HAVE_FMA4 1
#endif

// HAVE_FMA3

#undef HAVE_FMA3

/* Check for FMA3 support.
 * FMA3 is a fused multiply-add extension for x86 processors.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 * Supported by GCC with -mfma, MSVC with /arch:AVX2.
 */
#if defined(__FMA__) || \
    (defined(_WIN32) && defined(__AVX2__))
#  define HAVE_FMA3 1
#endif

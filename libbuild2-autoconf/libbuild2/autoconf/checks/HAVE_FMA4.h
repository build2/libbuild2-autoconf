// HAVE_FMA4

#undef HAVE_FMA4

/* Check for FMA4 support.
 * FMA4 is a fused multiply-add extension for x86 processors.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 * Supported by GCC with -mfma4, MSVC with /arch:AVX2.
 */
#if defined(__FMA4__) || \
    (defined(_WIN32) && defined(__AVX2__))
#  define HAVE_FMA4 1
#endif

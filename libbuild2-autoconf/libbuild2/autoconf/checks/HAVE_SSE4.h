// HAVE_SSE4

#undef HAVE_SSE4

/* Check for SSE4 support.
 * SSE4 is a SIMD extension for x86 processors, including SSE4.1 and SSE4.2.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 */
#if defined(__SSE4_1__) || \
    defined(__SSE4_2__)
#  define HAVE_SSE4 1
#endif
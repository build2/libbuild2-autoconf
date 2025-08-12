// HAVE__ALIGNED_MALLOC

#undef HAVE__ALIGNED_MALLOC

/* Check for the _aligned_malloc() function.
 *
 * Available on Windows including MinGW. Not available on Linux/glibc or MacOS.
 */
#if defined(_WIN32)
#  define HAVE__ALIGNED_MALLOC 1
#endif

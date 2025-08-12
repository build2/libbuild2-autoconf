// HAVE__BITSCANREVERSE

#undef HAVE__BITSCANREVERSE

/* Checks for the availability of the _BitScanReverse() intrinsic,
 * which identifies the position of the most significant set bit
 * in a given 32-bit integer.
 * This is a Microsoft-specific function available on Windows
 * platforms and some compatible compilers like MinGW.
 */
#if defined(_WIN32) && \
    (defined(__i386__) || defined(_M_IX86)  || defined(_M_ARM) || \
     defined(__x86_64__) || defined(_M_X64) || defined(_M_ARM64))
#  define HAVE__BITSCANREVERSE 1
#endif

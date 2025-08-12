// HAVE__BITSCANREVERSE

#undef HAVE__BITSCANREVERSE

/* Check for the _BitScanReverse() function.
 * _BitScanReverse() is a Microsoft intrinsic that identifies the position of
 * the most significant set bit in a 32-bit integer.
 *
 * Available on Windows including MinGW. Not available on Linux/glibc or MacOS.
 */
#if defined(_WIN32) && \
    (defined(__i386__)   || \
     defined(_M_IX86)    || \
     defined(_M_ARM)     || \
     defined(__x86_64__) || \
     defined(_M_X64)     || \
     defined(_M_ARM64))
#  define HAVE__BITSCANREVERSE 1
#endif

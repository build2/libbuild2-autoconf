// HAVE__BITSCANREVERSE64

#undef HAVE__BITSCANREVERSE64

/* Check for the _BitScanReverse64() function.
 * _BitScanReverse64() is a Microsoft intrinsic that identifies the position of
 * the most significant set bit in a 64-bit integer.
 *
 * Available on Windows including MinGW. Not available on Linux/glibc or MacOS.
 * Not supported by Clang.
 */
#if defined(_WIN32)     && \
    !defined(__clang__) && \
    (defined(__x86_64__) || \
     defined(_M_X64)     || \
     defined(_M_ARM64))
#  define HAVE__BITSCANREVERSE64 1
#endif

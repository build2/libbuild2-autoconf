// HAVE__BITSCANREVERSE64

#undef HAVE__BITSCANREVERSE64

/* Checks for the availability of the _BitScanReverse64() intrinsic,
 * which identifies the position of the most significant set bit in a
 * 64-bit integer.
 * This function is specific to Microsoft environments and is only
 * available on 64-bit architectures (x86_64).
 */
#if (defined(_WIN32) || defined(__MINGW32__)) && \
    defined(_M_X64)
#  define HAVE__BITSCANREVERSE64 1
#endif

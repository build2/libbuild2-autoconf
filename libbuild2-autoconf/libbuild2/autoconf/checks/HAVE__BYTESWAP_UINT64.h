// HAVE__BYTESWAP_UINT64

#undef HAVE__BYTESWAP_UINT64

/* Checks for the availability of the
 * _byteswap_UINT() intrinsic, which swaps
 * the byte order of a 64-bit unsigned int.
 * It is also a Microsoft-specific function
 * provided in <intrin.h>.
 */
#if defined(_WIN32) || defined(__MINGW32__)
#  define HAVE__BYTESWAP_UINT64 1
#endif

// HAVE__BYTESWAP_ULONG

#undef HAVE__BYTESWAP_ULONG

/* Checks for the availability of the
 * _byteswap_ulong() intrinsic, which swaps
 * the byte order of a 32-bit unsigned long.
 * It is also a Microsoft-specific function
 * provided in <intrin.h>.
 */
#if defined(_WIN32) || defined(__MINGW32__)
#  define HAVE__BYTESWAP_ULONG 1
#endif

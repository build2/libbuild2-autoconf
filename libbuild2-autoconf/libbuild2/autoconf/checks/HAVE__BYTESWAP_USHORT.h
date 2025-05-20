// HAVE__BYTESWAP_USHORT

#undef HAVE__BYTESWAP_USHORT

/* Checks for the availability of the
 * _byteswap_ulong() intrinsic, which swaps
 * the byte order of a 16-bit unsigned short.
 * It is also a Microsoft-specific function
 * provided in <intrin.h>.
 */
#if defined(_WIN32) || defined(__MINGW32__)
#  define HAVE__BYTESWAP_USHORT 1
#endif

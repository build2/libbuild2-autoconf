// HAVE__BYTESWAP_USHORT

#undef HAVE__BYTESWAP_USHORT

/* Check for the _byteswap_ushort() function.
 * _byteswap_ushort() is a Microsoft intrinsic that swaps the byte order of a
 * 16-bit unsigned short.
 *
 * Available on Windows including MinGW. Not available on Linux/glibc or MacOS.
 */
#if defined(_WIN32)
#  define HAVE__BYTESWAP_USHORT 1
#endif

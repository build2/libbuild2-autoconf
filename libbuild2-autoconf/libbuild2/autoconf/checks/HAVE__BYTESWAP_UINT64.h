// HAVE__BYTESWAP_UINT64

#undef HAVE__BYTESWAP_UINT64

/* Check for the _byteswap_uint64() function.
 * _byteswap_uint64() is a Microsoft intrinsic that swaps the byte order of a
 * 64-bit unsigned integer.
 *
 * Available on Windows including MinGW. Not available on Linux/glibc or MacOS.
 */
#if defined(_WIN32)
#  define HAVE__BYTESWAP_UINT64 1
#endif

// HAVE__BYTESWAP_ULONG

#undef HAVE__BYTESWAP_ULONG

/* Check for the _byteswap_ulong() function.
 * _byteswap_ulong() is a Microsoft intrinsic that swaps the byte order of a
 * 32-bit unsigned long.
 *
 * Available on Windows including MinGW. Not available on Linux/glibc or MacOS.
 */
#if defined(_WIN32)
#  define HAVE__BYTESWAP_ULONG 1
#endif

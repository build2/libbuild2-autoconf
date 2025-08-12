// HAVE___BUILTIN_BSWAP16

#undef HAVE___BUILTIN_BSWAP16

/* Checks for the availability of the __builtin_bswap16() macro or intrinsic.
 * __builtin_bswap16() swaps the byte order of a 16-bit integer.
 *
 * Available on OpenBSD, FreeBSD, NetBSD, Linux/glibc, MacOS. Not available on
 * Windows excluding MinGW.
 * Supported by GCC 5.0 and Clang 3.0.
 */
#if ((defined(__GNUC__) && (__GNUC__ >= 5)) || \
     (defined(__clang__) && (__clang_major__ >= 3))) && \
    !defined(_MSC_VER)
#  define HAVE___BUILTIN_BSWAP16 1
#endif

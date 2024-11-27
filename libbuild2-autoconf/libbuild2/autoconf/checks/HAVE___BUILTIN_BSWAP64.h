// HAVE___BUILTIN_BSWAP64

#undef HAVE___BUILTIN_BSWAP64

/* Checks for the availability of the __builtin_bswap64
 * macro or intrinsic, which swaps the byte order
 * of a 64-bit integer.
 * It is typically defined in system headers such
 * as <byteswap.h> on GNU-based systems or equivalent
 * headers on other platforms.
 */
#if ((defined(__GNUC__) && (__GNUC__ >= 5)) || \
     (defined(__clang__) && (__clang_major__ >= 3))) && \
    !defined(_WIN32)
#  define HAVE___BUILTIN_BSWAP64 1
#endif

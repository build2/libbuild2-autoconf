// HAVE___BUILTIN_BSWAP32

#undef HAVE___BUILTIN_BSWAP32

/* Checks for the availability of the __builtin_bswap32
 * macro or intrinsic, which swaps the byte order
 * of a 32-bit integer.
 * It is typically defined in system headers such
 * as <byteswap.h> on GNU-based systems or equivalent
 * headers on other platforms.
 */
#if ((defined(__GNUC__) && (__GNUC__ >= 5)) || \
     (defined(__clang__) && __has_builtin(__builtin_bswap32))) && \
    (!defined(_WIN32))
#  define HAVE___BUILTIN_BSWAP32 1
#endif

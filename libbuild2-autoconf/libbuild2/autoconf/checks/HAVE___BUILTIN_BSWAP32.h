// HAVE___BUILTIN_BSWAP32

#undef HAVE___BUILTIN_BSWAP32

/* Checks for the GCC/Clang built-in function __builtin_bswap32(),
 * which provides branch prediction hints.
 */
#if defined(__GNUC__) || defined(__clang__)
#  define HAVE___BUILTIN_BSWAP32 1
#endif

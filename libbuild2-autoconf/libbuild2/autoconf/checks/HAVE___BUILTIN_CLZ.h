// HAVE___BUILTIN_CLZ

#undef HAVE___BUILTIN_CLZ

/* Check determines if the __builtin_clz()
 * intrinsic is available. The function
 * calculates the number of leading zeros
 * in the binary representation of an integer.
 * It is provided by GCC and Clang for various
 * architectures and is highly optimized for
 * hardware that supports efficient bit manipulation.
 */
#if ((defined(__GNUC__) && (__GNUC__ >= 3)) || \
     (defined(__clang__) && (__clang_major__ >= 3))) && \
    !defined(_WIN32)
#  define HAVE___BUILTIN_CLZ 1
#endif

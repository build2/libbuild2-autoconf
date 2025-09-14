// HAVE___BUILTIN_CLZ

#undef HAVE___BUILTIN_CLZ

/* Check for the __builtin_clz() function.
 * __builtin_clz() is a GCC/Clang intrinsic that counts the number of leading
 * zeros in the binary representation of an integer.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 * Supported by GCC 3.0 or later and Clang 3.0 or later.
 */
#if ((defined(__GNUC__) && (__GNUC__ >= 3)) || \
     (defined(__clang__) && (__clang_major__ >= 3)))
#  define HAVE___BUILTIN_CLZ 1
#endif

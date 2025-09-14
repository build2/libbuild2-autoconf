// HAVE___BUILTIN_EXPECT

#undef HAVE___BUILTIN_EXPECT

/* Check for the __builtin_expect() function.
 * __builtin_expect() is a GCC/Clang intrinsic that provides branch prediction
 * hints to optimize performance.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 * Supported by GCC and Clang 3.0 or later.
 */
#if defined(__GNUC__) || (defined(__clang__) && (__clang_major__ >= 3))
#  define HAVE___BUILTIN_EXPECT 1
#endif

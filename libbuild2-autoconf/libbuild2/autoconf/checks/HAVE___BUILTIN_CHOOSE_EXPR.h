// HAVE___BUILTIN_CHOOSE_EXPR

#undef HAVE___BUILTIN_CHOOSE_EXPR

/* Check for the __builtin_choose_expr() function.
 * __builtin_choose_expr() is a GCC/Clang intrinsic that selects between two
 * expressions based on a constant condition at compile time.
 *
 * Available on Linux/glibc, MacOS. Not available on Windows including MinGW.
 * Supported by GCC 3.0 or later and Clang 3.0 or later.
 */
#if ((defined(__GNUC__) && (__GNUC__ >= 3)) || \
     (defined(__clang__) && (__clang_major__ >= 3))) && \
    !defined(_WIN32)
#  define HAVE___BUILTIN_CHOOSE_EXPR 1
#endif

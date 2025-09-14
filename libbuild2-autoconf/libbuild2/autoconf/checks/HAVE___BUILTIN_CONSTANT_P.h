// HAVE___BUILTIN_CONSTANT_P

#undef HAVE___BUILTIN_CONSTANT_P

/* Check for the __builtin_constant_p() function.
 * __builtin_constant_p() is a GCC/Clang intrinsic that determines at compile
 * time if an expression is a constant.
 *
 * Available on Linux/glibc, MacOS. Not available on Windows including MinGW.
 * Supported by GCC 3.0 or later and Clang 1.0 or later.
 */
#if ((defined(__GNUC__) && (__GNUC__ >= 3)) || \
     (defined(__clang__) && (__clang_major__ >= 1))) && \
    !defined(_WIN32)
#  define HAVE___BUILTIN_CONSTANT_P 1
#endif

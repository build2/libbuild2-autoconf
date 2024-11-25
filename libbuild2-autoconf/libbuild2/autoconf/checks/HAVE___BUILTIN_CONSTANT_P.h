// HAVE___BUILTIN_CONSTANT_P

#undef HAVE___BUILTIN_CONSTANT_P

/* Checks whether the __builtin_constant_p() intrinsic
 * is available. It is provided by GCC and GCC-compatible
 * compilers like Clang and is used to determine at
 * compile-time if an expression is a constant.
 */
#if ((defined(__GNUC__) && (__GNUC__ >= 3)) || \
     (defined(__clang__) && __has_builtin(__builtin_constant_p))) && \
    (!defined(_WIN32))
#  define HAVE___BUILTIN_CONSTANT_P 1
#endif

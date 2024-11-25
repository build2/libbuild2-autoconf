// HAVE___BUILTIN_CHOOSE_EXPR

#undef HAVE___BUILTIN_CHOOSE_EXPR

/* Check determines if the __builtin_choose_expr()
 * intrinsic is available. It is a compile-time
 * conditional expression provided by GCC and
 * supported by some GCC-compatible compilers like Clang.
 * It allows the selection between two expressions
 * based on a constant condition, evaluated at compile time.
 */
#if ((defined(__GNUC__) && (__GNUC__ >= 3)) || \
     (defined(__clang__) && __has_builtin(__builtin_choose_expr))) && \
    (!defined(_WIN32))
#  define HAVE___BUILTIN_CHOOSE_EXPR 1
#endif

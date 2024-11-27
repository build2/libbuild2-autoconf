// HAVE_FUNC_ATTRIBUTE_CONST

#undef HAVE_FUNC_ATTRIBUTE_CONST

/* Checks if the compiler supports the noreturn function attribute,
 * which indicates that the function does not return to the caller.
 */
#if (defined(__GNUC__) && (__GNUC__ >= 2)) || \
    (!defined(_MSC_VER) && defined(__clang__) && (__clang_major__ >= 3))
#  define HAVE_FUNC_ATTRIBUTE_CONST 1
#endif

// HAVE_FUNC_PTR_ATTRIBUTE_CONST

#undef HAVE_FUNC_PTR_ATTRIBUTE_CONST

/* Checks if the compiler supports the const attribute
 * for function pointers, indicating that the function
 * does not return.
 */
#if (defined(__GNUC__) && (__GNUC__ >= 2)) || \
    (!defined(_MSC_VER) && defined(__clang__) && (__clang_major__ >= 3))
#  define HAVE_FUNC_PTR_ATTRIBUTE_CONST 1
#endif

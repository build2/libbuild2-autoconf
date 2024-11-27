// HAVE_FUNC_PTR_ATTRIBUTE_NORETURN

#undef HAVE_FUNC_PTR_ATTRIBUTE_NORETURN

/* Checks if the compiler supports the noreturn attribute
 * for function pointers, indicating that the function
 * does not return.
 */
#if (defined(__GNUC__) && (__GNUC__ >= 2)) || \
    (!defined(_MSC_VER) && defined(__clang__) && (__clang_major__ >= 3))
#  define HAVE_FUNC_PTR_ATTRIBUTE_NORETURN 1
#endif

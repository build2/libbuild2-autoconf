// HAVE_FUNC_ATTRIBUTE_SENTINEL

#undef HAVE_FUNC_ATTRIBUTE_SENTINEL

/* Checks if the compiler supports the sentinel
 * attribute, which enforces a null-terminated
 * argument list for variadic functions.
 */
#if (defined(__GNUC__) && (__GNUC__ >= 3)) || \
    (!defined(_MSC_VER) && defined(__clang__) && (__clang_major__ >= 3))
#  define HAVE_FUNC_ATTRIBUTE_SENTINEL 1
#endif

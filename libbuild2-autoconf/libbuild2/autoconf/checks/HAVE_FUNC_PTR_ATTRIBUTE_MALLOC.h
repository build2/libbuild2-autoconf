// HAVE_FUNC_PTR_ATTRIBUTE_MALLOC

#undef HAVE_FUNC_PTR_ATTRIBUTE_MALLOC

/* Checks if the compiler supports the malloc attribute for
 * function pointers, indicating the return value is a
 * pointer to newly allocated memory.
 */
#if (defined(__GNUC__) && (__GNUC__ >= 3)) || \
    (!defined(_MSC_VER) && defined(__clang__) && (__clang_major__ >= 3))
#  define HAVE_FUNC_PTR_ATTRIBUTE_MALLOC 1
#endif

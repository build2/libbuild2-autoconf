// HAVE_FUNC_PTR_ATTRIBUTE_MALLOC

#undef HAVE_FUNC_PTR_ATTRIBUTE_MALLOC

/* Checks if the compiler supports the malloc attribute for
 * function pointers, indicating the return value is a
 * pointer to newly allocated memory.
 */
#if defined(__GNUC__) || defined(__clang__)
#  define HAVE_FUNC_ATPTR_ATTRIBUTE_MALLOC
#endif

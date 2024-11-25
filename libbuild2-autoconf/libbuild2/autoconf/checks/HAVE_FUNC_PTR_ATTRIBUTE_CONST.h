// HAVE_FUNC_PTR_ATTRIBUTE_CONST

#undef HAVE_FUNC_PTR_ATTRIBUTE_CONST

/* Checks if the compiler supports the const attribute
 * for function pointers, indicating that the function
 * does not return.
 */
#if defined(__GNUC__) || defined(__clang__)
#  define HAVE_FUNC_ATPTR_ATTRIBUTE_CONST
#endif

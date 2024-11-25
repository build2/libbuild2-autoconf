// HAVE_FUNC_PTR_ATTRIBUTE_NORETURN

#undef HAVE_FUNC_PTR_ATTRIBUTE_NORETURN

/* Checks if the compiler supports the noreturn attribute
 * for function pointers, indicating that the function
 * does not return.
 */
#if defined(__GNUC__) || defined(__clang__)
#  define HAVE_FUNC_ATPTR_ATTRIBUTE_NORETURN
#endif

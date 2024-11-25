// HAVE_FUNC_PTR_ATTRIBUTE_SENTINEL

#undef HAVE_FUNC_PTR_ATTRIBUTE_SENTINEL

/* Checks if the compiler supports the sentinel
 * attribute, which enforces a null-terminated
 * argument list for variadic function pointers.
 */
#if defined(__GNUC__) || defined(__clang__)
#  define HAVE_FUNC_PTR_ATTRIBUTE_SENTINEL 1
#endif

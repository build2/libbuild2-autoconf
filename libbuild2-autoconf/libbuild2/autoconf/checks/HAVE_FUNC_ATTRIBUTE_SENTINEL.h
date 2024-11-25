// HAVE_FUNC_ATTRIBUTE_SENTINEL

#undef HAVE_FUNC_ATTRIBUTE_SENTINEL

/* Checks if the compiler supports the sentinel
 * attribute, which enforces a null-terminated
 * argument list for variadic functions.
 */
#if defined(__GNUC__) || defined(__clang__)
#  define HAVE_FUNC_ATTRIBUTE_SENTINEL 1
#endif

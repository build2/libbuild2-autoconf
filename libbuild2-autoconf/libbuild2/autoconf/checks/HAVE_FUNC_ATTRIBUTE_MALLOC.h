// HAVE_FUNC_ATTRIBUTE_MALLOC

#undef HAVE_FUNC_ATTRIBUTE_MALLOC

/* Checks if the compiler supports the malloc function attribute,
 * which indicates that the function does not return to the caller.
 */
#if defined(__GNUC__) || defined(__clang__)
#  define HAVE_FUNC_ATTRIBUTE_MALLOC 1
#endif

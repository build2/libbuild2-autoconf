// HAVE_FUNC_PTR_ATTRIBUTE3_FORMAT

#undef HAVE_FUNC_PTR_ATTRIBUTE3_FORMAT

/* Checks if the compiler supports the format attribute, allowing
 * type-checking of printf/scanf-style function arguments.
 */
#if defined(__GNUC__) || defined(__clang__)
#  define HAVE_FUNC_PTR_ATTRIBUTE3_FORMAT 1
#endif

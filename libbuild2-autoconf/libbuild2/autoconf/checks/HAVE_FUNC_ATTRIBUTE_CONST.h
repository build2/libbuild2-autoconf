// HAVE_FUNC_ATTRIBUTE_CONST

#undef HAVE_FUNC_ATTRIBUTE_CONST

/* Checks if the compiler supports the noreturn function attribute,
 * which indicates that the function does not return to the caller.
 */
#if defined(__GNUC__) || defined(__clang__)
#  define HAVE_FUNC_ATTRIBUTE_CONST 1
#endif

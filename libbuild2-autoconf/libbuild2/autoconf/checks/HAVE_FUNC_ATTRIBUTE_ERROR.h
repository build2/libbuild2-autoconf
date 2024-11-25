// HAVE_FUNC_ATTRIBUTE_ERROR

#undef HAVE_FUNC_ATTRIBUTE_ERROR

/* Checks if the compiler supports the error function attribute, which
 * allows marking functions as compile-time errors when called.
 */
#if defined(__GNUC__)
#  define HAVE_FUNC_ATTRIBUTE_ERROR 1
#endif

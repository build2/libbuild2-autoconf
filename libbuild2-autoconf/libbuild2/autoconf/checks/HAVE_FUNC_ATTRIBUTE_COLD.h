// HAVE_FUNC_ATTRIBUTE_COLD

#undef HAVE_FUNC_ATTRIBUTE_COLD

/* Checks if the compiler supports the cold attribute,
 * which marks a function as unlikely to be executed.
 */
#if defined(__GNUC__) || defined(__clang__)
#  define HAVE_FUNC_ATTRIBUTE_COLD 1
#endif

// HAVE_FUNC_ATTRIBUTE_PURE

#undef HAVE_FUNC_ATTRIBUTE_PURE

/* Checks if the compiler supports the pure function attribute,
 * indicating a function’s return value depends only on its
 * arguments, with no global side effects.
 */
#if defined(__GNUC__) || defined(__clang__)
#  define HAVE_FUNC_ATTRIBUTE_PURE 1
#endif

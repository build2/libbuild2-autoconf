// HAVE_BUILTIN_CTZ

#undef HAVE_BUILTIN_CTZ

/* __builtin_ctz (count the leading/most-significant zeros in an unsigned int)
 * is available in all versions of GCC and Clang.
 */
#if defined (__GNUC__) || defined(__clang__)
#  define HAVE_BUILTIN_CTZ 1
#endif

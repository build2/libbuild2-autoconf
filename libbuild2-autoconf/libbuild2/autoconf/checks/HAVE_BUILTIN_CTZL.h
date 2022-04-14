// HAVE_BUILTIN_CTZL

#undef HAVE_BUILTIN_CTZL

/* __builtin_ctzl (count the leading/most-significant zeros in an unsigned
 * long) is available in all versions of GCC and Clang.
 */
#if defined (__GNUC__) || defined(__clang__)
#  define HAVE_BUILTIN_CTZL 1
#endif

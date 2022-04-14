// HAVE_BUILTIN_CTZLL

#undef HAVE_BUILTIN_CTZLL

/* __builtin_ctzll (count the leading/most-significant zeros in an unsigned
 * long long) is available in all versions of GCC and Clang.
 */
#if defined (__GNUC__) || defined(__clang__)
#  define HAVE_BUILTIN_CTZLL 1
#endif

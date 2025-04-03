// HAVE_FUNC_ATTRIBUTE_NONNULL

#undef HAVE_FUNC_ATTRIBUTE_NONNULL

/* Checks if the compiler supports the unused attribute for function
 * pointers, which can suppress warnings for unused function pointers.
 */
#if (defined(__GNUC__) && (__GNUC__ >= 4)) || \
    (!defined(_MSC_VER) && defined(__clang__) && (__clang_major__ >= 3))
#  define HAVE_FUNC_PTR_ATTRIBUTE_NONNULL 1
#endif

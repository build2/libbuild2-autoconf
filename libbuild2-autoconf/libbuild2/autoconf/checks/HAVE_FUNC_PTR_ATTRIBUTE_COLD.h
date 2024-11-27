// HAVE_FUNC_PTR_ATTRIBUTE_COLD

#undef HAVE_FUNC_PTR_ATTRIBUTE_COLD

/* Checks if the compiler supports the cold attribute,
 * which marks a function pointer as unlikely to be executed.
 */
#if (defined(__GNUC__) && (__GNUC__ >= 4)) || \
    (!defined(_MSC_VER) && defined(__clang__) && (__clang_major__ >= 3))
#  define HAVE_FUNC_PTR_ATTRIBUTE_COLD 1
#endif

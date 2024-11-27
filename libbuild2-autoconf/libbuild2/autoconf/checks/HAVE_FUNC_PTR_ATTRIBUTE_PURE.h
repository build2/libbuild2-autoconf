// HAVE_FUNC_PTR_ATTRIBUTE_PURE

#undef HAVE_FUNC_PTR_ATTRIBUTE_PURE

/* Checks if the compiler supports the pure function attribute,
 * indicating a function pointer return value depends only on its
 * arguments, with no global side effects.
 */
#if (defined(__GNUC__) && (__GNUC__ >= 3)) || \
    (!defined(_MSC_VER) && defined(__clang__) && (__clang_major__ >= 3))
#  define HAVE_FUNC_PTR_ATTRIBUTE_PURE 1
#endif

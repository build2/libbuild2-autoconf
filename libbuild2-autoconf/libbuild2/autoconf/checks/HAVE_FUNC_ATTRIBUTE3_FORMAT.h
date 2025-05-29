// HAVE_FUNC_ATTRIBUTE3_FORMAT

#undef HAVE_FUNC_ATTRIBUTE3_FORMAT

/* Checks if the compiler supports the format attribute, allowing
 * type-checking of printf/scanf-style function arguments.
 */
#if (defined(__GNUC__) && (__GNUC__ >= 3)) || \
    (!defined(_MSC_VER) && defined(__clang__) && (__clang_major__ >= 3))
#  define HAVE_FUNC_ATTRIBUTE3_FORMAT 1
#endif

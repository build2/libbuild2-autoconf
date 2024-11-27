// HAVE_FUNC_ATTRIBUTE1_ALLOC_SIZE

#undef HAVE_FUNC_ATTRIBUTE1_ALLOC_SIZE

/* Checks ensure that the compiler supports the alloc_size
 * function attribute, which specifies that a function
 * returns a pointer to allocated memory and optionally
 * indicates the size of the allocation.
 */
#if (defined(__GNUC__) && (__GNUC__ >= 4)) || \
    (!defined(_MSC_VER) && defined(__clang__) && (__clang_major__ >= 3))
#  define HAVE_FUNC_ATTRIBUTE1_ALLOC_SIZE 1
#endif

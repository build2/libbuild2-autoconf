// HAVE_VARIADIC_MACROS

#undef HAVE_VARIADIC_MACROS

/* Check if the compiler supports variadic macros.
 *
 * These were introduced in C99 but were already supported by MSVC 2005
 * (_MSC_VER 1400) and later and all versions of Clang.
 *
 * Note that although variadic macros were added to GCC 3 (circa 2001),
 * __VA_ARGS__ was not supported so disregard GCC when not in C99 mode or
 * later.
 */
#if (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)) || \
    defined(__clang__) || (defined(_MSC_VER) && _MSC_VER >= 1400)
#  define HAVE_VARIADIC_MACROS 1
#endif

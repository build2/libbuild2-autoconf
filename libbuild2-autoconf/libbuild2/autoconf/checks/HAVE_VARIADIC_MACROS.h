// HAVE_VARIADIC_MACROS

#undef HAVE_VARIADIC_MACROS

/* Checks if the compiler supports variadic macros, introduced
 * in C99 and available as a GNU extension.
 */
#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L) || \
    defined(__GNUC__) || defined(__clang__)
#  define HAVE_VARIADIC_MACROS 1
#endif

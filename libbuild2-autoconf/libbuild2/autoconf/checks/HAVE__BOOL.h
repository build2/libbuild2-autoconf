// HAVE__BOOL

#undef HAVE__BOOL

/* Checks if the _Bool type is supported,
 * which is standard in C99.
 */
#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)
#  define HAVE__BOOL 1
#endif

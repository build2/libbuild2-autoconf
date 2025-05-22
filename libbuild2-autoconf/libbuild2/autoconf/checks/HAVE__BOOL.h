// HAVE__BOOL

#undef HAVE__BOOL

/* Check for the C99 _Bool type.
 */
#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)
#  define HAVE__BOOL 1
#endif

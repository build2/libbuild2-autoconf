// HAVE_STDC_INLINE

#undef HAVE_STDC_INLINE

/* Checks if the compiler supports standard inline functions
 * according to the C99 specification (inline).
 */
#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)
#  define HAVE_STDC_INLINE 1
#endif

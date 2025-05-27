// HAVE__BOOL

#undef HAVE__BOOL

/* Check for the C99 _Bool type.
 *
 * @@ TMP Although this check does look correct, HAVE_STDBOOL_H is defined to
 *    1 unconditionally but <stdbool.h> defines bool to _Bool and thus
 *    logically depends on _Bool being available. Thus HAVE_STDBOOL_H should
 *    probably depend on this check but that might cause breakage.
 */
#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)
#  define HAVE__BOOL 1
#endif

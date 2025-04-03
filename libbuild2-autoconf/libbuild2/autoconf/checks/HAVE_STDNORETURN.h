// HAVE_STDNORETURN_H

#undef HAVE_STDNORETURN_H

/* Checks for the <stdnoreturn.h> header, introduced in C11,
 * which provides the noreturn specifier for functions that
 * do not return to the caller.
 */
#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)
#  define HAVE_STDNORETURN_H 1
#endif

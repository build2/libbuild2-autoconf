// HAVE_STDCKDINT_H

#undef HAVE_STDCKDINT_H

/* Check for the stdckdint.h header.
 *
 * Availabe since C23 and C++26 as the same header name.
 */
#if defined(__cplusplus)
#  if __cplusplus >= 202603L
#    define HAVE_STDCKDINT_H 1
#  endif
#elif defined(__STDC_VERSION__)
#  if __STDC_VERSION__ >= 202311L
#    define HAVE_STDCKDINT_H 1
#  endif
#endif

// HAVE___func__

#undef HAVE___func__

/* HAVE___func__
 * __func__ was added to the standard in C++11.
 */
#if (defined(__cplusplus) && __cplusplus >= 201103L) || defined(_MSVC_LANG) && (_MSVC_LANG >= 1900)
#   define HAVE___func__ 1
#endif

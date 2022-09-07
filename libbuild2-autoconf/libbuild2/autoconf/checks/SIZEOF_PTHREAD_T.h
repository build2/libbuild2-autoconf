// SIZEOF_PTHREAD_T

#undef SIZEOF_PTHREAD_T

/* Using the size of pointer appears to be a reasonable heuristics and
 *  __SIZEOF_POINTER__ is availbale everywhere where we have pthread (see
 *  SIZEOF_POINTER.h for details). Note also that we have a test that verifies
 *  this assumption.
 */
#ifndef _MSC_VER
#  ifdef __SIZEOF_POINTER__
#    define SIZEOF_PTHREAD_T __SIZEOF_POINTER__
#  endif

#  ifndef SIZEOF_PTHREAD_T
#    error unable to determine size of pthread_t
#  endif
#endif

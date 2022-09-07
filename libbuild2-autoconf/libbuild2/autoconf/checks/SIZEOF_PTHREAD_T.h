// SIZEOF_PTHREAD_T

#undef SIZEOF_PTHREAD_T

#ifndef _MSC_VER
#  ifdef __SIZEOF_POINTER__
#    define SIZEOF_PTHREAD_T __SIZEOF_POINTER__
#  endif

#  ifndef SIZEOF_PTHREAD_T
#    error unable to determine size of pthread_t
#  endif
#endif

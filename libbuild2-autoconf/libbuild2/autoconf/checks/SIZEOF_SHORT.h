// SIZEOF_SHORT

#undef SIZEOF_SHORT

#ifdef _MSC_VER
#  define SIZEOF_SHORT 2
#else
/* Both GCC and Clang (and maybe others) define __SIZEOF_SHORT__. */
#  ifdef __SIZEOF_SHORT__
#    define SIZEOF_SHORT __SIZEOF_SHORT__
#  endif
#endif

#ifndef SIZEOF_SHORT
#  error unable to determine size of short
#endif

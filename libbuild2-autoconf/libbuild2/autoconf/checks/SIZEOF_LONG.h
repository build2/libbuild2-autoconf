// SIZEOF_LONG

#undef SIZEOF_LONG

#ifdef _MSC_VER
#  define SIZEOF_LONG 4
#else
/* Both GCC and Clang (and maybe others) define __SIZEOF_LONG__. */
#  ifdef __SIZEOF_LONG__
#    define SIZEOF_LONG __SIZEOF_LONG__
#  endif
#endif

#ifndef SIZEOF_LONG
#  error unable to determine size of long int
#endif

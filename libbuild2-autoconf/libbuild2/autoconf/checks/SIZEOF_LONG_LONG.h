// SIZEOF_LONG_LONG

#undef SIZEOF_LONG_LONG

#ifdef _MSC_VER
#  define SIZEOF_LONG_LONG 8
#else
/* Both GCC and Clang (and maybe others) define __SIZEOF_LONG_LONG__. */
#  ifdef __SIZEOF_LONG_LONG__
#    define SIZEOF_LONG_LONG __SIZEOF_LONG_LONG__
#  endif
#endif

#ifndef SIZEOF_LONG_LONG
#  error unable to determine size of long long
#endif

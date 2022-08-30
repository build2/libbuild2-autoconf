// SIZEOF_INT

#undef SIZEOF_INT

#ifdef _MSC_VER
#  define SIZEOF_INT 4
#else
/* Both GCC and Clang (and maybe others) define __SIZEOF_INT__. */
#  ifdef __SIZEOF_INT__
#    define SIZEOF_INT __SIZEOF_INT__
#  endif
#endif

#ifndef SIZEOF_INT
#  error unable to determine size of int
#endif

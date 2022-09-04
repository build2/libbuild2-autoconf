// SIZEOF_POINTER

/* See also SIZEOF_SIZE_T (the two may not be the same), SIZEOF_VOID_P. */

#undef SIZEOF_POINTER

#ifdef _MSC_VER
/* _WIN64 is defined for both x64 (x86_64) and ARM64 (aarch64). */
#  ifdef _WIN64
#    define SIZEOF_POINTER 8
#  else
#    define SIZEOF_POINTER 4
#  endif
#else
/* Both GCC and Clang (and maybe others) define __SIZEOF_POINTER__. */
#  ifdef __SIZEOF_POINTER__
#    define SIZEOF_POINTER __SIZEOF_POINTER__
#  endif
#endif

#ifndef SIZEOF_POINTER
#  error unable to determine size of pointer
#endif

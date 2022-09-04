// SIZEOF_VOID_P

/* See also SIZEOF_SIZE_T (the two may not be the same), SIZEOF_POINTER. */

#undef SIZEOF_VOID_P

#ifdef _MSC_VER
/* _WIN64 is defined for both x64 (x86_64) and ARM64 (aarch64). */
#  ifdef _WIN64
#    define SIZEOF_VOID_P 8
#  else
#    define SIZEOF_VOID_P 4
#  endif
#else
/* Both GCC and Clang (and maybe others) define __SIZEOF_POINTER__. */
#  ifdef __SIZEOF_POINTER__
#    define SIZEOF_VOID_P __SIZEOF_POINTER__
#  endif
#endif

#ifndef SIZEOF_VOID_P
#  error unable to determine size of pointer
#endif

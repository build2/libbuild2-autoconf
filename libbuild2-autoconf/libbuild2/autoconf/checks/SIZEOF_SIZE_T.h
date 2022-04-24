// SIZEOF_SIZE_T

/* See also SIZEOF_POINTER (the two may not be the same). */

#undef SIZEOF_SIZE_T

#ifdef _MSC_VER
/* _WIN64 is defined for both x64 (x86_64) and ARM64 (aarch64). */
#  ifdef _WIN64
#    define SIZEOF_SIZE_T 8
#  else
#    define SIZEOF_SIZE_T 4
#  endif
#else
/* Both GCC and Clang (and maybe others) define __SIZEOF_SIZE_T__. */
#  ifdef __SIZEOF_SIZE_T__
#    define SIZEOF_SIZE_T __SIZEOF_SIZE_T__
#  endif
#endif

#ifndef SIZEOF_SIZE_T
#  error unable to determine size of size_t
#endif

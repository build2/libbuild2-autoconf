// SIZEOF_OFF_T

#undef SIZEOF_OFF_T


/* Use __SIZEOF_SIZE_T__ (defined by GCC and Clang and maybe others) to detect
 * a 64-bit target.
 *
 * Note that the _FILE_OFFSET_BITS macro is expected to be defined by the
 * user, for example, on the command line.
 *
 * MinGW uses 32-bit off_t both in the 32-bit and 64-bit modes unless forced
 * with _FILE_OFFSET_BITS.
 */

#ifdef _MSC_VER
#  define SIZEOF_OFF_T 4
#elif defined(__MINGW32__)
#  if defined(_FILE_OFFSET_BITS) && _FILE_OFFSET_BITS == 64
#    define SIZEOF_OFF_T 8
#  else
#    define SIZEOF_OFF_T 4
#  endif
#elif (defined(__SIZEOF_SIZE_T__) && __SIZEOF_SIZE_T__ == 8) || \
      (defined(_FILE_OFFSET_BITS) && _FILE_OFFSET_BITS == 64)
#  define SIZEOF_OFF_T 8
#else
#  define SIZEOF_OFF_T 4
#endif

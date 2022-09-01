// SIZEOF_OFF_T

#undef SIZEOF_OFF_T

/* Note that the _FILE_OFFSET_BITS macro is expected to be defined by the
 * user, for example, on the command line.
 */

#ifdef _MSC_VER
#  define SIZEOF_OFF_T 4
#elif defined(__x86_64__) || defined(__ppc64__) || (defined(_FILE_OFFSET_BITS) && _FILE_OFFSET_BITS == 64)
#  define SIZEOF_OFF_T 8
#else
#  define SIZEOF_OFF_T 4
#endif

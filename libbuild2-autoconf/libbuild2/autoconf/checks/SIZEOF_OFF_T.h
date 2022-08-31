// SIZEOF_OFF_T

#undef SIZEOF_OFF_T

#ifdef _MSC_VER
#  define SIZEOF_OFF_T 4
#elif __x86_64__ || __ppc64__ || _FILE_OFFSET_BITS == 64
#  define SIZEOF_OFF_T 8
#else
#  define SIZEOF_OFF_T 4
#endif

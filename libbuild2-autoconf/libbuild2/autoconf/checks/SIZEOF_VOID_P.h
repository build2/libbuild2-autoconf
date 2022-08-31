// SIZEOF_VOID_P

#undef SIZEOF_VOID_P

#if _WIN64 || __x86_64__ || __ppc64__
#  define SIZEOF_VOID_P 8
#else
#  define SIZEOF_VOID_P 4
#endif

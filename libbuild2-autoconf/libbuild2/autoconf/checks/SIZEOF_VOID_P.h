// SIZEOF_VOID_P

#undef SIZEOF_VOID_P

/* @@ TODO: redo using SIZEOF_POINTER (see SIZEOF_SIZE_T). */

#if defined(_WIN64) || defined(__x86_64__) || defined(__ppc64__)
#  define SIZEOF_VOID_P 8
#else
#  define SIZEOF_VOID_P 4
#endif

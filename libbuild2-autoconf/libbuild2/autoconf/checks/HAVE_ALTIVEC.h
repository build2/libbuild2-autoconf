// HAVE_ALTIVEC

#undef HAVE_ALTIVEC

/* PowerPC (POWER1 and later)
 */
#if defined(__powerpc) || \
    defined(__powerpc__) || \
    defined(__powerpc64__) || \
    defined(__POWERPC__) || \
    defined(__ppc__) || \
    defined(__PPC__) || \
    defined(_ARCH_PPC)
#  define HAVE_ALTIVEC 1
#endif

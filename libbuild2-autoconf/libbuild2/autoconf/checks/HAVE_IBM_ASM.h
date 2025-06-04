// HAVE_IBM_ASM

#undef HAVE_IBM_ASM

/* IBM architecture that supports IBM assembly language,
 * specifically PowerPC (PPC) or IBM Z (z/Architecture).
 */
#if (defined(__powerpc__) || defined(__ppc__) || defined(__PPC__) || defined(__powerpc64__) || defined(__PPC64__) || \
     defined(__s390__) || defined(__s390x__) || \
     defined(__IBMC__) || defined(__IBMCPP__))
#  define HAVE_IBM_ASM 1
#endif

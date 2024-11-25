// HAVE_DCBZL

#undef HAVE_DCBZL

/* Since PowerPC 603 processor (mid-1990s).
 */
#if defined(__powerpc__) || defined(__ppc__) || defined(__PPC__)
#  define HAVE_DCBZL 1
#endif

// HAVE_DCBZL

#undef HAVE_DCBZL

/* Check for dcbzl instruction support.
 * dcbzl is a PowerPC instruction for zeroing a cache block.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 */
#if defined(__powerpc__)   || \
    defined(__ppc__)       || \
    defined(__PPC__)       || \
    defined(__powerpc64__) || \
    defined(__PPC64__)
#  define HAVE_DCBZL 1
#endif

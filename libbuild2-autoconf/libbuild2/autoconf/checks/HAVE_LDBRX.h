// HAVE_LDBRX

#undef HAVE_LDBRX

/* Check for ldbrx instruction support.
 * ldbrx is a PowerPC instruction for loading a byte-reversed doubleword.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 */
#if defined(__powerpc__)   || \
    defined(__ppc__)       || \
    defined(__PPC__)       || \
    defined(__powerpc64__) || \
    defined(__PPC64__)
#  define HAVE_LDBRX 1
#endif

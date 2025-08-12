// HAVE_ALTIVEC

#undef HAVE_ALTIVEC

/* Check for AltiVec support.
 * AltiVec is a SIMD vector extension for PowerPC processors.
 *
 * Available on Linux/glibc, FreeBSD, OpenBSD, NetBSD, MacOS, Windows including
 * MinGW.
 */
#if defined(__powerpc)     || \
    defined(__powerpc__)   || \
    defined(__powerpc64__) || \
    defined(__POWERPC__)   || \
    defined(__ppc__)       || \
    defined(__PPC__)       || \
    defined(_ARCH_PPC)
#  define HAVE_ALTIVEC 1
#endif

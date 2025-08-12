// HAVE_PPC4XX

#undef HAVE_PPC4XX

/* Check for PowerPC 4xx processor support.
 * PowerPC 4xx is an embedded PowerPC processor family.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 */
#if defined(__powerpc__) && defined(__PPC4XX__)
#  define HAVE_PPC4XX 1
#endif
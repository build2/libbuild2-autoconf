// HAVE_PPC4XX

#undef HAVE_PPC4XX

/* Presence of PowerPC 4xx processors,
 * typically found in embedded systems.
 */
#if defined(__powerpc__) && defined(__PPC4XX__)
#  define HAVE_PPC4XX 1
#endif

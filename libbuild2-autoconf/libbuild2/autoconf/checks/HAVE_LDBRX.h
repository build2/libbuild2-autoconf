// HAVE_LDBRX

#undef HAVE_LDBRX

/* Load Doubleword Byte-Reversed Indexed instruction,
 * which is specific to the PowerPC (PPC) architecture.
 */
#if defined(__powerpc__) || defined(__ppc__) || defined(__PPC__) || defined(__powerpc64__) || defined(__PPC64__)
#  define HAVE_LDBRX 1
#endif

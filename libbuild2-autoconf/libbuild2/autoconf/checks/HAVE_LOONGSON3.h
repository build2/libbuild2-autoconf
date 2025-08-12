// HAVE_LOONGSON3

#undef HAVE_LOONGSON3

/* Check for Loongson 3 processor support.
 * Loongson 3 is a MIPS-based processor family.
 *
 * Available on Linux/glibc. Not available on MacOS or Windows including MinGW.
 */
#if defined(__loongson__) && defined(__loongson3__)
#  define HAVE_LOONGSON3 1
#endif

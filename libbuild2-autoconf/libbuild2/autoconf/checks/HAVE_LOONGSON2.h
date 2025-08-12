// HAVE_LOONGSON2

#undef HAVE_LOONGSON2

/* Check for Loongson 2 processor support.
 * Loongson 2 is a MIPS-based processor family.
 *
 * Available on Linux/glibc. Not available on MacOS or Windows including MinGW.
 */
#if defined(__loongson__)    && \
    (defined(__loongson2f__) || \
     defined(__loongson2e__))
#  define HAVE_LOONGSON2 1
#endif

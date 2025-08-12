// HAVE_MSA

#undef HAVE_MSA

/* Check for MSA support.
 * MSA is the MIPS SIMD Architecture extension.
 *
 * Available on Linux/glibc. Not available on MacOS, Windows including MinGW.
 */
#if defined(__mips_msa)
#  define HAVE_MSA 1
#endif

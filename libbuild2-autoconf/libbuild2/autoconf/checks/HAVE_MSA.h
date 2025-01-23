// HAVE_MSA

#undef HAVE_MSA

/* Presence of MIPS SIMD Architecture (MSA), which
 * provides SIMD instructions for MIPS processors.
 */
#if defined(__mips_msa)
#  define HAVE_MSA 1
#endif

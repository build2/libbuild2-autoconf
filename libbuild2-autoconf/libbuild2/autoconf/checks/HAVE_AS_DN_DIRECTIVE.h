// HAVE_AS_DN_DIRECTIVE

#undef HAVE_AS_DN_DIRECTIVE

/* Assembly feature.
 * Available in ARMv8 and later.
 * See: https://sourceware.org/binutils/docs/as/ARM-Directives.html
 * Note: Apple Silicon (M1 and later) uses ARMv8 architecture but has different preprocessor macros.
 */
#if (defined(__ARM_NEON) || defined(__ARM_ARCH_ISA_A64)) || (defined(__APPLE__) && (defined(__arm64__) || defined(__arm64e__)))
#  if defined(__ARM_ARCH) && __ARM_ARCH >= 8 || (defined(__APPLE__) && (defined(__arm64__) || defined(__arm64e__)))
#    define HAVE_AS_DN_DIRECTIVE 1
#  endif
#endif

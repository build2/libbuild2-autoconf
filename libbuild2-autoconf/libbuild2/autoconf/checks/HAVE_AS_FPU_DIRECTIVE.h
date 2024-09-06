// HAVE_AS_FPU_DIRECTIVE

#undef HAVE_AS_FPU_DIRECTIVE

/* Assembly feature.
 * Available in ARMV8 and later.
 * See: https://sourceware.org/binutils/docs/as/ARM-Directives.html
 */
#if defined(__ARM_ARCH)
#  if __ARM_ARCH >= 8
#    define HAVE_AS_FPU_DIRECTIVE 1
#  endif
#endif

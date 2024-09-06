// HAVE_AS_ARCH_DIRECTIVE

#undef HAVE_AS_ARCH_DIRECTIVE

/* Assembly directive '.arch'
 * AFAICS this exists on ARM since very old versions.
 */
#if defined(__ARM_ARCH)
#  define HAVE_AS_ARCH_DIRECTIVE 1
#endif

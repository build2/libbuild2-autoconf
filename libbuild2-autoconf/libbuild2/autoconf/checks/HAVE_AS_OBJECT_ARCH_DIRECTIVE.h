// HAVE_AS_OBJECT_ARCH_DIRECTIVE

#undef HAVE_AS_OBJECT_ARCH_DIRECTIVE

/* Assembly directive '.object_arch'
 * AFAICS this exists on ARM since very old versions.
 */
#if defined(__ARM_ARCH)
#  define HAVE_AS_OBJECT_ARCH_DIRECTIVE 1
#endif

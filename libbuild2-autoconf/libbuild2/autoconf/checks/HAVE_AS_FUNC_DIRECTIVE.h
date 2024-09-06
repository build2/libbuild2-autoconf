// HAVE_AS_FUNC_DIRECTIVE

#undef HAVE_AS_FUNC_DIRECTIVE

/* Assembly directive '.func'/'.function'
 * AFAICS this exists on ARM since very old versions.
 */
#if defined(__ARM_ARCH)
#  define HAVE_AS_FUNC_DIRECTIVE 1
#endif

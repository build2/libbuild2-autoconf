// HAVE_AS_ARCHEXT_DOTPROD

#undef HAVE_AS_ARCHEXT_DOTPROD

/* Assembly feature.
 * Available in Cortex-A75, Cortex-A55, and Neoverse N1 and later.
 */
#if defined(__ARM_FEATURE_DOTPROD)
#  define HAVE_AS_ARCHEXT_DOTPROD 1
#endif

// HAVE_VFPV3

#undef HAVE_VFPV3

/* Presence of VFP v3 on ARM platforms.
 */
#if defined(__VFP_FP__) && defined(__ARM_ARCH_7A__)
#  define HAVE_VFPV3 1
#endif

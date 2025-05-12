// HAVE_VFPV4

#undef HAVE_VFPV4

/* Presence of VFP v4 on ARM platforms.
 */
#if defined(__VFP_FP__) && defined(__ARM_ARCH_8A__)
#  define HAVE_VFPV4 1
#endif

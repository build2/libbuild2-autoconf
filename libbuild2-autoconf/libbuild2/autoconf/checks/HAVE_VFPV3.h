// HAVE_VFPV3

#undef HAVE_VFPV3

/* Check for VFPv3 support.
 * VFPv3 is version 3 of the ARM Vector Floating Point extension.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 */
#if defined(__VFP_FP__) && defined(__ARM_ARCH_7A__)
#  define HAVE_VFPV3 1
#endif
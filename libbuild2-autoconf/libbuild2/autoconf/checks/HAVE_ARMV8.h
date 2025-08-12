// HAVE_ARMV8

#undef HAVE_ARMV8

/* Check for ARMv8 architecture support.
 * ARMv8 is the 64-bit version of the ARM architecture, also known as AArch64.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 */
#if defined(__ARM_ARCH) && __ARM_ARCH == 8
#  define HAVE_ARMV8 1
#endif

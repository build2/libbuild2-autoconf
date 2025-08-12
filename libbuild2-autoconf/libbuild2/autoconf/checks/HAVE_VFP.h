// HAVE_VFP

#undef HAVE_VFP

/* Check for VFP support.
 * VFP is a floating-point extension for ARM processors.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 */
#ifdef __ARM_VFP__
#  define HAVE_VFP 1
#endif
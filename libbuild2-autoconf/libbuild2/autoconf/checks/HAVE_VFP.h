// HAVE_VFP

#undef HAVE_VFP

/* Presence of Vector Floating Point (VFP), which is an extension
 * for ARM processors providing floating-point arithmetic instructions.
 */
#ifdef __ARM_VFP__
#  define HAVE_VFP 1
#endif

// HAVE_VFP_ARGS

#undef HAVE_VFP_ARGS

/* If the system passes arguments to functions using
 * VFP (Vector Floating Point) registers, common on ARM systems.
 */
#ifdef __ARM_PCS_VFP
#  define HAVE_VFP_ARGS 1
#endif

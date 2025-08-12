// HAVE_VFP_ARGS

#undef HAVE_VFP_ARGS

/* Check for VFP arguments support.
 * VFP arguments support means passing function arguments in VFP registers on
 * ARM.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 */
#ifdef __ARM_PCS_VFP
#  define HAVE_VFP_ARGS 1
#endif
// HAVE_XFORM_ASM

#undef HAVE_XFORM_ASM

/* Check for transformation assembly support.
 * Transformation assembly includes optimized assembly code for image or video
 * processing.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 */
#ifdef __XFORM_ASM__
#  define HAVE_XFORM_ASM 1
#endif
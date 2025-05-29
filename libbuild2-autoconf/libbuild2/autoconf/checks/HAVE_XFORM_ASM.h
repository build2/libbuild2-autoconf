// HAVE_XFORM_ASM

#undef HAVE_XFORM_ASM

/* Presence of transformation-related assembly optimizations,
 * typically for image or video processing tasks.
 */
#ifdef __XFORM_ASM__
#  define HAVE_XFORM_ASM 1
#endif

// HAVE_VSX

#undef HAVE_VSX

/* Presence of Vector Scalar Extension (VSX) support, an extension to
 * the PowerPC architecture that enhances SIMD and floating-point operations.
 */
#ifdef __VSX__
#  define HAVE_VSX 1
#endif

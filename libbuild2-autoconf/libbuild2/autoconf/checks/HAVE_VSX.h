// HAVE_VSX

#undef HAVE_VSX

/* Check for VSX support.
 * VSX is the Vector Scalar Extension for PowerPC processors.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 */
#ifdef __VSX__
#  define HAVE_VSX 1
#endif
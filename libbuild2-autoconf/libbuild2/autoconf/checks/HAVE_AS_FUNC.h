// HAVE_AS_FUNC

#undef HAVE_AS_FUNC

/* Check for .func directive in assembly.
 * .func directive marks the start of a function in ARM assembly code.
 *
 * Available on Linux/glibc, Windows including MinGW. Not available on MacOS.
 */
#if defined(__ARM_ARCH) && !defined(__APPLE__)
#  define HAVE_AS_FUNC 1
#endif

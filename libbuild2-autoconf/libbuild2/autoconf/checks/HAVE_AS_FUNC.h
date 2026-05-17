// HAVE_AS_FUNC

#undef HAVE_AS_FUNC

/* Check for the .func directive in assembly.
 * The .func/.endfunc directives mark function start/end in ARM assembly code.
 *
 * Available on Linux/glibc and Windows including MinGW with GCC (which uses
 * GAS). Not available with Clang (both Apple's and upstream LLVM's integrated
 * assemblers do not implement .func/.endfunc) or on MacOS.
 */
#if defined(__ARM_ARCH) && !defined(__clang__)
#  define HAVE_AS_FUNC 1
#endif

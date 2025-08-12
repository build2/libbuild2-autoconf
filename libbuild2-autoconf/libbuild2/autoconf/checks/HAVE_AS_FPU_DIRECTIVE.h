// HAVE_AS_FPU_DIRECTIVE

#undef HAVE_AS_FPU_DIRECTIVE

/* Check for .fpu directive in assembly.
 * .fpu directive specifies the floating-point unit in ARM assembly code.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 */
#if (defined(__ARM_ARCH) || \
    (defined(__APPLE__) && (defined(__arm64__) || defined(__arm64e__)))) && \
    (defined(__ARM_ARCH) && __ARM_ARCH >= 8)   || \
    (defined(__APPLE__) && (defined(__arm64__) || defined(__arm64e__)))
#  define HAVE_AS_FPU_DIRECTIVE 1
#endif

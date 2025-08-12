// HAVE_AS_DN_DIRECTIVE

#undef HAVE_AS_DN_DIRECTIVE

/* Check for .dn directive in assembly.
 * .dn directive defines a register name alias in ARM assembly code.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 */
#if ((defined(__ARM_NEON) || defined(__ARM_ARCH_ISA_A64)) || \
     (defined(__APPLE__) && (defined(__arm64__) || defined(__arm64e__)))) && \
    (defined(__ARM_ARCH) && __ARM_ARCH >= 8)   || \
    (defined(__APPLE__) && (defined(__arm64__) || defined(__arm64e__)))
#  define HAVE_AS_DN_DIRECTIVE 1
#endif

// HAVE_ARM_ASM

#undef HAVE_ARM_ASM

/* Check for ARM assembly support.
 * ARM assembly is supported on compilers targeting ARM architectures.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 * Supported by GCC, Clang.
 */
#if (defined(__GNUC__) || defined(__clang__)) && \
    (defined(__ARM_ARCH) || \
     defined(__arm__)    || \
     defined(__aarch64__))
#  define HAVE_ARM_ASM 1
#endif

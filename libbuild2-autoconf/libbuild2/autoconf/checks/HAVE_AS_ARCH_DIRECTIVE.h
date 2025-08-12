// HAVE_AS_ARCH_DIRECTIVE

#undef HAVE_AS_ARCH_DIRECTIVE

/* Check for .arch directive in assembly.
 * .arch directive specifies the target architecture in ARM assembly code.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 */
#if defined(__ARM_ARCH)
#  define HAVE_AS_ARCH_DIRECTIVE 1
#endif
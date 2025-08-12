// HAVE_AS_ARCHEXT_I8MM_DIRECTIVE

#undef HAVE_AS_ARCHEXT_I8MM_DIRECTIVE

/* Check for .arch_extension i8mm support in assembly.
 * .arch_extension i8mm enables 8-bit integer matrix multiplication in
 * ARMv8.6-A and later.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 */
#if defined(__ARM_ARCH) && __ARM_ARCH >= 8
#  define HAVE_AS_ARCHEXT_I8MM_DIRECTIVE 1
#endif

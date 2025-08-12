// HAVE_AS_ARCHEXT_DOTPROD_DIRECTIVE

#undef HAVE_AS_ARCHEXT_DOTPROD_DIRECTIVE

/* Check for .arch_extension dotprod support in assembly.
 * .arch_extension dotprod enables dot product instructions in ARMv8.2-A and
 * later.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 */
#if defined(__ARM_FEATURE_DOTPROD)
#  define HAVE_AS_ARCHEXT_DOTPROD_DIRECTIVE 1
#endif

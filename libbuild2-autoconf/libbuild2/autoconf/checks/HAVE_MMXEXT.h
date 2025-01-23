// HAVE_MMXEXT : HAVE_X86ASM

#undef HAVE_MMXEXT

/* Presence of MMXEXT instructions:
 * - Checks for explicit __MMXEXT__ definition first
 * - Falls back to compiler-specific checks for likely MMXEXT support
 */
#if defined(__MMXEXT__) || \
    defined(HAVE_X86ASM)
#  define HAVE_MMXEXT 1
#endif

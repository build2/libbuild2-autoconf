// HAVE_MMX : HAVE_X86ASM

#undef HAVE_MMX

/* Presence of MMX instructions:
 * - Checks for explicit __MMX__ definition first
 * - Falls back to compiler-specific checks for likely MMX support
 */
#if defined(__MMX__) || \
    defined(HAVE_X86ASM)
#  define HAVE_MMX 1
#endif

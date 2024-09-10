// HAVE_X86ASM

#undef HAVE_X86ASM

/* Presence of x86 assembly support, ensuring that the system can
 * execute inline assembly or external assembly for x86 processors.
 */
#if defined(__i386__)
#  define HAVE_X86ASM 1
#endif

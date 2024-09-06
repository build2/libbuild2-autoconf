// HAVE_ASM_EBX

#undef HAVE_ASM_EBX

/* x86 excluding ARM, PowerPC, MIPS & RISC-V.
 */
#if defined(__i386__)
#  if !defined(__arm__) && !defined(__powerpc__) && \
      !defined(__ppc__) && \
      !defined(__mips__) && \
      !defined(__riscv__) && !defined(__riscv)
#    define HAVE_ASM_EBX 1
#  endif
#endif

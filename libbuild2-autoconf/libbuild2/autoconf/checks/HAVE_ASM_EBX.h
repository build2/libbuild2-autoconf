// HAVE_ASM_EBX

#undef HAVE_ASM_EBX

/* x86 (available on x86_64 under RBX) excluding ARM, PowerPC, MIPS & RISC-V.
 */
#if defined(__i386__) || \
    defined(__x86_64__) || \
    (defined(_M_IX86) || defined(_M_X64))
#  if !defined(__arm__) && !defined(__powerpc__) && \
      !defined(__ppc__) && \
      !defined(__mips__) && \
      !defined(__riscv__) && !defined(__riscv)
#    define HAVE_ASM_EBX 1
#  endif
#endif

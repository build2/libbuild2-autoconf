// HAVE_ASM_EBP

#undef HAVE_ASM_EBP

/* Check for EBP (Extended Base Pointer) support in assembly on x86/x86_64,
 * excluding unsupported architectures (ARM, PowerPC, MIPS, RISC-V)
 * and excluding Windows x64 with MSVC due to calling convention limitations.
 */
#if (defined(__i386__) || defined(__x86_64__) || defined(_M_IX86) || defined(_M_X64)) && \
    !(defined(_WIN32) && defined(_MSC_VER) && defined(_M_X64)) && \
    !defined(__arm__) && !defined(__aarch64__) && \
    !defined(__powerpc__) && !defined(__ppc__) && \
    !defined(__mips__) && !defined(__riscv)
    #define HAVE_ASM_EBP 1
#else
    #define HAVE_ASM_EBP 0
#endif

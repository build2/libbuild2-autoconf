// HAVE_EBP_AVAILABLE

#undef HAVE_EBP_AVAILABLE

/* Check for EBP support in assembly.
 * EBP is the Extended Base Pointer register in x86 assembly, used for stack
 * frame access.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 */
#if (defined(__i386__)    || \
     defined(__x86_64__)  || \
     defined(_M_IX86)     || \
     defined(_M_X64))     && \
    !(defined(_WIN32)     && \
      defined(_MSC_VER)   && \
      defined(_M_X64))    && \
    !defined(__arm__)     && \
    !defined(__aarch64__) && \
    !defined(__powerpc__) && \
    !defined(__ppc__)     && \
    !defined(__mips__)    && \
    !defined(__riscv)
#  define HAVE_EBP_AVAILABLE 1
#endif

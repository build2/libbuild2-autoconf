// HAVE_EBX_AVAILABLE

#undef HAVE_EBX_AVAILABLE

/* Check for EBX support in assembly.
 * EBX is the Extended Base register in x86 assembly, used for indexing and
 * general-purpose operations.
 *
 * Available on Linux/glibc, MacOS. Not available on Windows x86-64 excluding
 * MinGW.
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
#  define HAVE_EBX_AVAILABLE 1
#endif

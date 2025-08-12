// HAVE_RV

#undef HAVE_RV

/* Check for RISC-V architecture support.
 * RISC-V is an open-source instruction set architecture.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 */
#if defined(__riscv__) || \
    defined(__riscv)
#  define HAVE_RV 1
#endif
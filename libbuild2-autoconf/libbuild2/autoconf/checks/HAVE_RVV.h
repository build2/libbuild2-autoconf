// HAVE_RVV

#undef HAVE_RVV

/* Check for RVV support.
 * RVV is the RISC-V Vector extension.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 */
#if defined(__riscv_vector)
#  define HAVE_RVV 1
#endif
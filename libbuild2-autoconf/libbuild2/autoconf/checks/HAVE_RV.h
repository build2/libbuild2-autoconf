// HAVE_RV

#undef HAVE_RV

/* Presence of RISC-V architecture (RV) support in the environment.
 */
#if defined(__riscv__) || defined(__riscv)
#  define HAVE_RV 1
#endif

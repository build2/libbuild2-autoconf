// HAVE_RVV

#undef HAVE_RVV

/* Presence of RISC-V Vector Extension (RVV), which adds vector
 * processing capabilities to the base RISC-V architecture.
 */
#if defined(__riscv_vector)
#  define HAVE_RVV 1
#endif

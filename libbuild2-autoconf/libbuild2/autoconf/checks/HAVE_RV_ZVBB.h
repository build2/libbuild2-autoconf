// HAVE_RV_ZVBB

#undef HAVE_RV_ZVBB

/* Presence of ZVBB extension of the RISC-V ISA, which
 * adds vector bit-manipulation instructions.
 */
#if defined(__riscv_zvbb)
#  define HAVE_RV_ZVBB 1
#endif

// HAVE_ASM_HWPROBE_H

#undef HAVE_ASM_HWPROBE_H

/* AFAICS this is exclusively a Risc-V thing.
 */

#if defined(__riscv)
#  define HAVE_ASM_HWPROBE_H 1
#endif

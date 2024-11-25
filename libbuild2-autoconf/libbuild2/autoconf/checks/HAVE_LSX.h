// HAVE_LSX

#undef HAVE_LSX

/* GCC, Clang: -mlsx (https://gcc.gnu.org/onlinedocs/gcc/LoongArch-Options.html)
 * Supported on LoongArch (https://github.com/loongson/la-toolchain-conventions?tab=readme-ov-file#cc-preprocessor-built-in-macro-definitions)
 */
#ifdef __loongarch_sx
#  define HAVE_LSX 1
#endif

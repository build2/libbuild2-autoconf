// HAVE_LASX

#undef HAVE_LASX

/* GCC, Clang: -mlasx (https://gcc.gnu.org/onlinedocs/gcc/LoongArch-Options.html)
 * Supported on LoongArch (https://github.com/loongson/la-toolchain-conventions?tab=readme-ov-file#cc-preprocessor-built-in-macro-definitions)
 */
#ifdef __loongarch_asx
#  define HAVE_LASX 1
// LASX implies LSX
#  ifndef HAVE_LSX
#    define HAVE_LSX 1
#  endif
#endif

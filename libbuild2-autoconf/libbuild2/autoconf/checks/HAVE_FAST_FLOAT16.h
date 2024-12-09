// HAVE_FAST_FLOAT16

#undef HAVE_FAST_FLOAT16

/* Checks for the availability of fast `_Float16` support.
 * `_Float16` is natively supported on:
 * - GCC (11.0+) with supported architectures (ARM, x86 with AVX-512FP16, RISC-V V-extension).
 * - Clang with similar architecture support.
 * - ARM platforms with NEON or SVE.
 * MSVC does not support `_Float16`.
 */

#if (defined(__GNUC__) && __GNUC__ >= 11) || defined(__clang__)
#  if defined(__ARM_FEATURE_FP16_SCALAR_ARITHMETIC) || \
      defined(__ARM_NEON) || \
      defined(__AVX512FP16__) || \
      defined(__riscv_zfh)
#    define HAVE_FAST_FLOAT16 1
#  endif
#endif

// HAVE_INLINE_ASM

#undef HAVE_INLINE_ASM

/* Indicates whether inline assembly is supported by the compiler.
 * Note: MSVC supports inline assembly but only in 32-bit mode.
         Inline assembly is not supported in 64-bit MSVC
 */
#if (defined(__GNUC__) || defined(__clang__) || defined(__INTEL_COMPILER) || \
     (defined(_MSC_VER) && !defined(_M_X64)) || defined(__IBMC__) || defined(__IBMCPP__) || \
     defined(__ARMCC_VERSION))
#  define HAVE_INLINE_ASM 1
#endif

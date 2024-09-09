// HAVE_INLINE_ASM_DIRECT_SYMBOL_REFS

#undef HAVE_INLINE_ASM_DIRECT_SYMBOL_REFS

/* Indicates if the compiler supports direct symbol references in inline assembly.
 * GCC and Clang support direct symbol references in inline assembly.
 * MSVC allows direct symbol references only in 32-bit mode (not in 64-bit mode).
 */
#if defined(__GNUC__) || defined(__clang__) || \
    (defined(_MSC_VER) && !defined(_M_X64))
#  define HAVE_INLINE_ASM_DIRECT_SYMBOL_REFS 1
#endif

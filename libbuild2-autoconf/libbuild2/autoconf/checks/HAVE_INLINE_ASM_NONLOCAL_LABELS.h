// HAVE_INLINE_ASM_NONLOCAL_LABELS

#undef HAVE_INLINE_ASM_NONLOCAL_LABELS

/* Indicates if the compiler supports non-local labels in inline assembly.
 * GCC and Clang support non-local labels in inline assembly.
 * MSVC might support non-local labels in 32-bit mode, but not in 64-bit mode.
 */
#if defined(__GNUC__) || defined(__clang__) || \
    (defined(_MSC_VER) && !defined(_M_X64))
#  define HAVE_INLINE_ASM_NONLOCAL_LABELS 1
#endif

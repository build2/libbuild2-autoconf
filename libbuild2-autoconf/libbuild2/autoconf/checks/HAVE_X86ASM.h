// HAVE_X86ASM

#undef HAVE_X86ASM

/* Presence of x86 assembly support, ensuring that the system can
 * execute inline assembly or external assembly for x86 processors.
 */
#if defined(__i386__) || \
    defined(__x86_64__) || \
    (defined(_M_IX86) || defined(_M_X64)) && (defined(_MSC_VER) || defined(__GNUC__) || defined(__clang__))
#  define HAVE_X86ASM 1
#endif

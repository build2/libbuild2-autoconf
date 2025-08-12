// HAVE_X86_ASM

#undef HAVE_X86_ASM

/* Check for x86 assembly support.
 * x86 assembly is supported on compilers targeting x86 architectures.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 * Supported by GCC, Clang, MSVC.
 */
#if defined(__i386__)   || \
    defined(__x86_64__) || \
    (defined(_M_IX86)  || defined(_M_X64)) && \
    (defined(_MSC_VER) || defined(__GNUC__) || defined(__clang__))
#  define HAVE_X86_ASM 1
#endif

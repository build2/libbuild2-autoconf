// HAVE_MMX

#undef HAVE_MMX

/* Check for MMX support.
 * MMX is a SIMD instruction set for x86 processors.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 */
#if defined(__MMX__)     || \
    (defined(__i386__)   || \
     defined(__x86_64__) || \
     defined(_M_IX86)    || \
     defined(_M_X64)) && \
    (defined(_MSC_VER) || defined(__GNUC__) || defined(__clang__))
#  define HAVE_MMX 1
#endif

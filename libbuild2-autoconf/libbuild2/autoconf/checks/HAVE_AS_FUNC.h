// HAVE_AS_FUNC

#undef HAVE_AS_FUNC

/* Check for the .func directive in assembly.
 * The .func/.endfunc directives mark function start/end in ARM assembly code.
 *
 * Only implemented by GNU as. Available on Linux/glibc with GCC. Not available
 * on Windows except MinGW (GCC). Not available on MacOS (the system assembler
 * is LLVM-based, even with GCC) or with Clang (integrated assembler).
 *
 * Note that __ARM_ARCH is predefined by GCC and Clang when targeting ARM and
 * __GNUC__ is predefined by GCC and Clang (but not MSVC).
 */
#if defined(__ARM_ARCH) && \
    defined(__GNUC__)   && \
    !defined(__clang__) && \
    !defined(__APPLE__)
#  define HAVE_AS_FUNC 1
#endif

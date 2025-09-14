// HAVE_FAST_UNALIGNED

#undef HAVE_FAST_UNALIGNED

/* Check for fast unaligned memory access support.
 * Fast unaligned memory access is the capability to access memory that is not
 * aligned to the natural word size without performance penalty.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 * Available on x86 and x86-64, ARMv7-A or later, ARMv8-A (64-bit), PowerPC
 * with AltiVec.
 * Supported by GCC and MSVC.
 */
#if defined(__x86_64__) || \
    defined(__i386__)   || \
    defined(_M_IX86)    || \
    defined(_M_X64)
#  define HAVE_FAST_UNALIGNED 1
#elif defined(__ARM_ARCH) && (__ARM_ARCH >= 7)
#  define HAVE_FAST_UNALIGNED 1
#elif defined(__aarch64__)
#  define HAVE_FAST_UNALIGNED 1
#elif defined(__POWERPC__) && defined(__ALTIVEC__)
#  define HAVE_FAST_UNALIGNED 1
#endif

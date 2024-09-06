// HAVE_FAST_UNALIGNED

#undef HAVE_FAST_UNALIGNED

/* Platforms and compilers supporting efficient unaligned memory access.
 */
#if defined(__x86_64__) || defined(__i386__)  /* x86 and x86-64 (Intel and AMD) */
/* x86 and x86-64 platforms have efficient unaligned memory access */
#  define HAVE_FAST_UNALIGNED 1
#elif defined(__ARM_ARCH) && (__ARM_ARCH >= 7) /* ARMv7-A or later */
/* ARMv7-A and ARMv8-A architectures support fast unaligned access */
#  define HAVE_FAST_UNALIGNED 1
#elif defined(__aarch64__)  /* ARM 64-bit (ARMv8) */
/* ARMv8-A (64-bit) has fast unaligned access */
#  define HAVE_FAST_UNALIGNED 1
#elif defined(__POWERPC__) && defined(__ALTIVEC__) /* PowerPC with AltiVec support */
/* Some PowerPC platforms with AltiVec might support efficient unaligned access */
#  define HAVE_FAST_UNALIGNED 1
#endif

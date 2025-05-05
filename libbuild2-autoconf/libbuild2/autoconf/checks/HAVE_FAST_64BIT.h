// HAVE_FAST_64BIT : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_FAST_64BIT

/* Presence of optimized support for 64-bit arithmetic operations.
 * Virtually on all systems if targeting 64-bit.
 */
#if defined(_WIN64) \
    || defined(__x86_64__) || defined(__x86_64) \
    || defined(__ppc64__) || defined(__PPC64__) \
    || defined(__aarch64__) \
    || defined(__mips64__) \
    || defined(__powerpc64__) \
    || defined(__s390x__) \
    || (defined(__sparc__) && defined(__arch64__)) \
    || defined(__riscv_xlen) && __riscv_xlen == 64
#  define HAVE_FAST_64BIT 1
#endif

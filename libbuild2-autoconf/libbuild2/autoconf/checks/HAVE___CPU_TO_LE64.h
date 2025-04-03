// HAVE___CPU_TO_LE64

#undef HAVE___CPU_TO_LE64

/* These checks verify whether the __cpu_to_le64
 * macros or intrinsics is available. This macro
 * convert integers from CPU (host) endianness to
 * little-endian format.
 */
#if (defined(__linux__) && defined(__KERNEL__))     || \
    (defined(__FreeBSD__) && defined(_KERNEL))   || \
    defined(__OpenBSD__) || defined(__NetBSD__)
#  define HAVE___CPU_TO_LE64 1
#endif

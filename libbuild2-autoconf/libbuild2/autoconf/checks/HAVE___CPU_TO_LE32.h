// HAVE___CPU_TO_LE32

#undef HAVE___CPU_TO_LE32

/* These checks verify whether the __cpu_to_le32
 * macros or intrinsics is available. This macro
 * convert integers from CPU (host) endianness to
 * little-endian format.
 */
#if (defined(__linux__) && defined(__KERNEL__))     || \
    (defined(__FreeBSD__) && defined(_KERNEL))   || \
    defined(__OpenBSD__) || defined(__NetBSD__)
#  define HAVE___CPU_TO_LE32 1
#endif

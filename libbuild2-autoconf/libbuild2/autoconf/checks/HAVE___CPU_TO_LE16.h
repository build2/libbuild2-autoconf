// HAVE___CPU_TO_LE16

#undef HAVE___CPU_TO_LE16

/* These checks verify whether the __cpu_to_le16
 * macros or intrinsics is available. This macro
 * convert integers from CPU (host) endianness to
 * little-endian format.
 */
#if (defined(__linux__) && defined(__KERNEL__))     || \
    (defined(__FreeBSD__) && defined(_KERNEL))   || \
    defined(__OpenBSD__) || defined(__NetBSD__)
#  define HAVE___CPU_TO_LE16 1
#endif

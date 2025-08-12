// HAVE___CPU_TO_LE16

#undef HAVE___CPU_TO_LE16

/* Checks if the __cpu_to_le16() macro or intrinsic is available.
 * Convert integers from CPU (host) endianness to little-endian format.
 *
 * Available on Linux, FreeBSD, OpenBSD, NetBSD. Not available on MacOS or
 * Windows including MinGW.
 */
#if (defined(__linux__) && defined(__KERNEL__)) || \
    (defined(__FreeBSD__) && defined(_KERNEL))  || \
    defined(__OpenBSD__)                        || \
    defined(__NetBSD__)
#  define HAVE___CPU_TO_LE16 1
#endif

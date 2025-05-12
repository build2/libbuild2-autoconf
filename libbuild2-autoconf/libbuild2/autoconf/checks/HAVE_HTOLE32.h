// HAVE_HTOLE32

#undef HAVE_HTOLE32

/* Checks for a macro or function to convert a 32-bit
 * integer from host to little-endian format.
 */
#if defined(__linux__) || \
    defined(__FreeBSD__) || \
    defined(__NetBSD__) || \
    defined(__OpenBSD__)
#  define HAVE_HTOLE32 1
#endif

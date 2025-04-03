// HAVE_HTOLE16

#undef HAVE_HTOLE16

/* Checks for a macro or function to convert a 16-bit
 * integer from host to little-endian format.
 */
#if defined(__linux__) || \
    defined(__FreeBSD__) || \
    defined(__NetBSD__) || \
    defined(__OpenBSD__)
#  define HAVE_HTOLE16 1
#endif

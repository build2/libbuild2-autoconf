// HAVE_HTOLE64

#undef HAVE_HTOLE64

/* Checks for a macro or function to convert a 64-bit
 * integer from host to little-endian format.
 */
#if defined(__linux__) || \
    defined(__FreeBSD__) || \
    defined(__NetBSD__) || \
    defined(__OpenBSD__)
#  define HAVE_HTOLE64 1
#endif

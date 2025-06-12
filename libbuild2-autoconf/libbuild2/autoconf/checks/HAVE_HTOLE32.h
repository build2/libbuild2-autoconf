// HAVE_HTOLE32 : HAVE_HTOLE16

#undef HAVE_HTOLE32

/* Check for the htole32() macro/function which converts a 32-bit integer from
 * host to little-endian format.
 *
 * Added at the same time as htole16() on all platforms checked.
 */
#ifdef HAVE_HTOLE16
#  define HAVE_HTOLE32 1
#endif

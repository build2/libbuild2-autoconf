// HAVE_HTOLE64 : HAVE_HTOLE16

#undef HAVE_HTOLE64

/* Check for the htole64() macro/function which converts a 64-bit integer from
 * host to little-endian format.
 *
 * Added at the same time as htole16() on all platforms checked.
 */
#ifdef HAVE_HTOLE16
#  define HAVE_HTOLE64 1
#endif

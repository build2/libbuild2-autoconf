// HAVE_ATTRIBUTE_PACKED

#undef HAVE_ATTRIBUTE_PACKED

/* Check for the __attribute__((packed)) attribute.
 *
 * Available on Linux/glibc, Mac OS, and Windows including MinGW. Not
 * available on MSVC.
 */
#if defined(__GNUC__) || \
    defined(__clang__)
#  define HAVE_ATTRIBUTE_PACKED 1
#endif

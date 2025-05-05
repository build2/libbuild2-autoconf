// HAVE_ENDIAN_H

#undef HAVE_ENDIAN_H

/* This checks if the endian.h header is available, which provides macros
 * for byte-order manipulation.
 */
#if defined(__linux__) || \
    defined(__FreeBSD__) || \
    defined(__NetBSD__) || \
    defined(__OpenBSD__)
#  define HAVE_ENDIAN_H 1
#endif


// HAVE_ENDIAN_H

#undef HAVE_ENDIAN_H

/* Check for the endian.h header which provides macros for byte-order
 * manipulation.
 */
#if defined(__GLIBC__) || \
    defined(__OpenBSD__)
#  define HAVE_ENDIAN_H 1
#endif

// HAVE_SYS_ENDIAN_H

#undef HAVE_SYS_ENDIAN_H

/* Check for the sys/endian.h header which provides macros for byte-order
 * manipulation.
 */
#if defined(__FreeBSD__) || \
    defined(__NetBSD__)
#  define HAVE_SYS_ENDIAN_H 1
#endif

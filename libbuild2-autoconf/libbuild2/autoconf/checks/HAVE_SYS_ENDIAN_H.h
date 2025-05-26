// HAVE_SYS_ENDIAN_H

#undef HAVE_SYS_ENDIAN_H

/* This checks if the sys/endian.h header is available, which provides macros
 * for byte-order manipulation.
 */
#if defined(__FreeBSD__) || \
    defined(__NetBSD__)
#  define HAVE_SYS_ENDIAN_H 1
#endif

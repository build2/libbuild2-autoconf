// HAVE_MACHINE_ENDIAN_H

#undef HAVE_MACHINE_ENDIAN_H

/* This checks if the machine/endian.h header is available, which provides
 * macros for byte-order manipulation.
 */
#if defined(__APPLE__)
#  define HAVE_MACHINE_ENDIAN_H 1
#endif

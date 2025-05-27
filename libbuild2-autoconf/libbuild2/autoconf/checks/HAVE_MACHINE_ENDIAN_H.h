// HAVE_MACHINE_ENDIAN_H

#undef HAVE_MACHINE_ENDIAN_H

/* Check for the machine/endian.h header which provides macros for byte-order
 * manipulation.
 */
#if defined(__APPLE__)
#  define HAVE_MACHINE_ENDIAN_H 1
#endif

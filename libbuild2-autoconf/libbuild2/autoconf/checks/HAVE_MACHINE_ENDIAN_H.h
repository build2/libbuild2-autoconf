// HAVE_MACHINE_ENDIAN_H

#undef HAVE_MACHINE_ENDIAN_H

/* Checks for the machine/endian.h header, which
 * defines machine-specific endianness macros.
 */
#if defined(__FreeBSD__) || \
    defined(__NetBSD__) || \
    defined(__OpenBSD__)
#  define HAVE_MACHINE_ENDIAN_H 1
#endif

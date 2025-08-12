// HAVE_ASM_TYPES_H

#undef HAVE_ASM_TYPES_H

/* Check for the <asm/types.h> header.
 * <asm/types.h> provides architecture-specific data types for assembly code.
 *
 * Available on Linux/glibc. Not available on Windows or MacOS.
 */
#if defined(__linux__)
#  define HAVE_ASM_TYPES_H 1
#endif

// HAVE_SYS_SYSMACROS_H

#undef HAVE_SYS_SYSMACROS_H

/* Check for the sys/sysmacros.h header.
 *
 * Only provided on Linux.
 */
#if defined(__linux__)
#  define HAVE_SYS_SYSMACROS_H 1
#endif

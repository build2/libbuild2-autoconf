// HAVE_ASM_TYPES_H

#undef HAVE_ASM_TYPES_H

/* Since Linux 2.2.
 */
#if defined(__linux__)
#  define HAVE_ASM_TYPES_H 1
#endif

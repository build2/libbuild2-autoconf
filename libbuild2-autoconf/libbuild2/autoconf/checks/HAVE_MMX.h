// HAVE_MMX

#undef HAVE_MMX

/* Presence of MMX instructions, which are extensions to the original
 * MMX instruction set, available on AMD processors starting from K6-2.
 * Since glibc 2.0 (x86), FreeBSD (x86), OpenBSD (x86), NetBSD (x86),
 * MacOS 10.04 (x86), MSVC
 */
#if defined(__MMX__) || \
    defined(_M_IX86) || defined(_M_X64)
#  define HAVE_MMX 1
#endif

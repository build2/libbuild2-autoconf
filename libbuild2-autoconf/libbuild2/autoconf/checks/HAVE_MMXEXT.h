// HAVE_MMXEXT

#undef HAVE_MMXEXT

/* Presence of MMXEXT instructions, which are extensions to the original
 * MMX instruction set, available on AMD processors starting from K6-2.
 * Since glibc 2.0 (x86), FreeBSD (x86), OpenBSD (x86), NetBSD (x86),
 * MacOS 10.04 (x86), MSVC
 */
#if defined(__MMXEXT__) || \
    defined(_M_IX86) || defined(_M_X64)
#  define HAVE_MMXEXT 1
#endif

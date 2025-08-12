// HAVE_MMXEXT

#undef HAVE_MMXEXT

/* Check for MMXEXT support.
 * MMXEXT is an extension to the MMX instruction set for x86 processors.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 */
#if defined(__MMXEXT__)  || \
    (defined(__i386__)   || \
     defined(__x86_64__) || \
     defined(_M_IX86)    || \
     defined(_M_X64))
#  define HAVE_MMXEXT 1
#endif

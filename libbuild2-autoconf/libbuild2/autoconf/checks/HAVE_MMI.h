// HAVE_MMI

#undef HAVE_MMI

/* Check for MMI support.
 * MMI is a Multimedia Instructions set for MIPS processors.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 */
#if defined(__mips__)
#  define HAVE_MMI 1
#endif
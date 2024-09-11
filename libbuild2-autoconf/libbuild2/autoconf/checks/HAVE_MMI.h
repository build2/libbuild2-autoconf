// HAVE_MMI

#undef HAVE_MMI

/* Presence of MMI (Multimedia Instructions), typically used in specific
 * CPU architectures for multimedia processing, like in certain MIPS processors.
 * Linux
 */
#if defined(__mips__)
#  define HAVE_MMI 1
#endif

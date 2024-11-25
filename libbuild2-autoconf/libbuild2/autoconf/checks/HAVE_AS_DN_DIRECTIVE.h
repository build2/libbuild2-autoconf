// HAVE_AS_DN_DIRECTIVE

#undef HAVE_AS_DN_DIRECTIVE

/* Assembly feature.
 * Available in ARMV8 and later.
 * See: https://sourceware.org/binutils/docs/as/ARM-Directives.html
 */
#if defined(__ARM_NEON) || defined(__ARM_NEON__)
#  define HAVE_AS_DN_DIRECTIVE 1
#endif

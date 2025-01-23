// HAVE_ALTIVEC

#undef HAVE_ALTIVEC

/* PowerPC (POWER1 and later) + compiler flag
 */
#if defined(__VEC__) || defined(__ALTIVEC__)
#  define HAVE_ALTIVEC 1
#endif

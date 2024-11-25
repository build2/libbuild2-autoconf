// HAVE_MM_EMPTY

#undef HAVE_MM_EMPTY

/* Presence of the _mm_empty() function (from <mmintrin.h>), associated
 * with MMX technology, specifically multimedia extensions found in
 * x86 architecture systems.
 */
#if defined(__MMX__)
#  define HAVE_MM_EMPTY 1
#endif

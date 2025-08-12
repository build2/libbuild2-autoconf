// HAVE_MM_EMPTY

#undef HAVE_MM_EMPTY

/* Check for mm_empty() function.
 * mm_empty() is an MMX function that empties the MMX state.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 */
#if defined(__MMX__)
#  define HAVE_MM_EMPTY 1
#endif

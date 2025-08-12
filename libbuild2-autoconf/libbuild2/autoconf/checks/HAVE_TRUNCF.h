// HAVE_TRUNCF : HAVE_TRUNC

#undef HAVE_TRUNCF

/* Checks for the truncf() function from <math.h>.
 *
 * trunc() and truncf() were added at the same time in all of the systems I
 * checked (see HAVE_TRUNC.h)
 */
#ifdef HAVE_TRUNC
#  define HAVE_TRUNCF 1
#endif

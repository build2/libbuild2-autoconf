// HAVE_VSNPRINTF : HAVE_SNPRINTF

#undef HAVE_VSNPRINTF

/* Check for the vsnprintf() function which formats a string into a buffer
 * with variable arguments.
 *
 * vsnprintf() and snprintf() were added at the same time in all of the
 * systems I checked (see HAVE_SNPRINTF.h).
 */
#ifdef HAVE_SNPRINTF
#  define HAVE_VSNPRINTF 1
#endif

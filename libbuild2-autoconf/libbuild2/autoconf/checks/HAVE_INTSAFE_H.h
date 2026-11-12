// HAVE_INTSAFE_H

#undef HAVE_INTSAFE_H

/* Check for the intsafe.h header.
 *
 * Only available on Windows.
 */
#if defined(_WIN32)
#  define HAVE_INTSAFE_H 1
#endif

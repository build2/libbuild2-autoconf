// HAVE_GETHRTIME

#undef HAVE_GETHRTIME

/* Solaris
 */
#if ((defined(__sun) && defined(__SVR4)) || defined(__sun__))
#  define HAVE_GETHRTIME 1
#endif

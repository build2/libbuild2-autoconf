// HAVE_EXPLICIT_MEMSET

#undef HAVE_EXPLICIT_MEMSET

/* Since NetBSD 7.0.0.
 */
#if defined(__NetBSD_Version__) && __NetBSD_Version__ >= 700000000
#  define HAVE_EXPLICIT_MEMSET 1
#endif

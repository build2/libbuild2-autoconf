// HAVE_LOCALTIME_S

#undef HAVE_LOCALTIME_S

/*  Check for the localtime_s() function.
 *
 *  This function is defined by the optional C11 Annex K and is only provided
 *  on Windows. All POSIX targets appears to prefer POSIX localtime_r().
 */
#ifdef _WIN32
#  define HAVE_LOCALTIME_S 1
#endif

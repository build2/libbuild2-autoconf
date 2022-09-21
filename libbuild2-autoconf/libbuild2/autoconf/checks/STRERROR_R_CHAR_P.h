// STRERROR_R_CHAR_P

#undef STRERROR_R_CHAR_P

/* GNU-specific.
 *
 * Note that while the HAVE_STRERROR_R_CHAR_P would have been the better
 * name (since we are testing for presence/absence), this name is used by
 * the autoconf's AC_FUNC_STRERROR_R test.
 */
#ifdef __GLIBC__
#  if defined(_GNU_SOURCE) || (_POSIX_C_SOURCE < 200112L)
#    define STRERROR_R_CHAR_P 1
#  endif
#endif

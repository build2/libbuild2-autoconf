// HAVE_STRERROR_R_CHAR_P

#undef HAVE_STRERROR_R_CHAR_P

/* GNU-specific.
 */
#ifdef __GLIBC__
#  if defined(_GNU_SOURCE) || (_POSIX_C_SOURCE < 200112L)
#    define HAVE_STRERROR_R_CHAR_P 1
#  endif
#endif

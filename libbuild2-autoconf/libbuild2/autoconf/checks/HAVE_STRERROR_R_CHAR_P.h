// HAVE_STRERROR_R_CHAR_P : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_STRERROR_R_CHAR_P

/* GNU specific
 */
#if defined(_GNU_SOURCE) || (_POSIX_C_SOURCE < 200112L)
#  define HAVE_STRERROR_R_CHAR_P 1
#endif

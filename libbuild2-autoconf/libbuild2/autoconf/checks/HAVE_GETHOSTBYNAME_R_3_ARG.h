// HAVE_GETHOSTBYNAME_R_3_ARG : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_GETHOSTBYNAME_R_3_ARG

/* AIX4, HPUX 10 uses 3 args
 */
#if defined(_AIX) || defined(__hpux)
#  define HAVE_GETHOSTBYNAME_R_3_ARG 1
#endif

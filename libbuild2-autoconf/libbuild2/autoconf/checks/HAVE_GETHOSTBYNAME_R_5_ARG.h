// HAVE_GETHOSTBYNAME_R_5_ARG : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_GETHOSTBYNAME_R_5_ARG

/* Solaris uses 5 args starting from at latest 5.5 could not find earlier.
 */
#if defined(__SunOS) && defined(__SunOS_5_5)
#  define HAVE_GETHOSTBYNAME_R_5_ARG 1
#endif

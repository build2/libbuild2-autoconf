// HAVE_GETHOSTBYNAME_R : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_GETHOSTBYNAME_R

/* Since Linux/glibc 2.1, SunOS, AIX and HPUX.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 1)       || \
    defined(__SunOS) && defined(__SunOS_5_5) || \
    defined(_AIX) || \
    defined(__hpux)
#  define HAVE_GETHOSTBYNAME_R 1
#endif

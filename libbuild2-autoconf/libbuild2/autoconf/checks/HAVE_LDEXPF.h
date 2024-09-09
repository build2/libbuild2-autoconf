// HAVE_LDEXPF : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_LDEXPF

/*  Availability of the ldexpf() function, which is part of the C standard library.
 */
#if (__STDC_VERSION__ >= 199901L) || defined(__GNUC__) || defined(__clang__) || \
    (defined(_MSC_VER) && (_MSC_VER >= 1800)) || defined(_POSIX_VERSION)
#  define HAVE_LDEXPF 1
#endif

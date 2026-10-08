// HAVE_STRLCAT : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_STRLCAT

/* strl*() are available since glibc 2.38 but is only enabled if __USE_MISC
   is defined (normally via _GNU_SOURCE or _DEFAULT_SOURCE). */

#if defined(__FreeBSD__) || \
    defined(__OpenBSD__) || \
    defined(__NetBSD__)  || \
    defined(__APPLE__)
#  define HAVE_STRLCAT 1
#elif BUILD2_AUTOCONF_GLIBC_PREREQ(2, 38)
#  include <features.h> /* __USE_MISC */
#  ifdef __USE_MISC
#    define HAVE_STRLCAT 1
#  endif
#endif

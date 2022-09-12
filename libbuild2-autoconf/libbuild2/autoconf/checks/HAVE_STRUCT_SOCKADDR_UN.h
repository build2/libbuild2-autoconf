// HAVE_STRUCT_SOCKADDR_UN : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_STRUCT_SOCKADDR_UN

/* Linux/glibc 1.09, Since 4.4BSD (~1995)
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(1, 9) || \
    defined(__FreeBSD__)                || \
    defined(__OpenBSD__)                || \
    defined(__NetBSD__)                 || \
    defined(BUILD2_AUTOCONF_MACOS)
#  define HAVE_STRUCT_SOCKADDR_UN 1
#endif

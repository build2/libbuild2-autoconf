// HAVE_STRUCT_SOCKADDR_STORAGE : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_STRUCT_SOCKADDR_STORAGE

/* Linux/glibc 2.1.1, Since 4.2BSD (~1983), Windows
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 2)  || \
    defined(__FreeBSD__)                || \
    defined(__OpenBSD__)                || \
    defined(__NetBSD__)                 || \
    defined(BUILD2_AUTOCONF_MACOS)      || \
    defined(_WIN32)
#  define HAVE_STRUCT_SOCKADDR_STORAGE 1
#endif

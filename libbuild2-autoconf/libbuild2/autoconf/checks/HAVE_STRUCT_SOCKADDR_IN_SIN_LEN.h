// HAVE_STRUCT_SOCKADDR_IN_SIN_LEN : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_STRUCT_SOCKADDR_IN_SIN_LEN

/* Since 4.3BSD (OpenBSD, FreeBSD, NetBSD, Mac OS X)
 *  'The length member, sin_len, was added with 4.3BSD-Reno [..]'
 */
#if defined(__FreeBSD__)            || \
    defined(__OpenBSD__)            || \
    defined(__NetBSD__)             || \
    defined(BUILD2_AUTOCONF_MACOS)
#  define HAVE_STRUCT_SOCKADDR_IN_SIN_LEN 1
#endif

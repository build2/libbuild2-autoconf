// HAVE_STRUCT_SOCKADDR_SA_LEN : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_STRUCT_SOCKADDR_SA_LEN

/* Check for the presence of the sa_len field in the sockaddr structure which
 * defines the length of the address structure.
 *
 * FreeBSD, OpenBSD, NetBSD, and macOS.
 */
#if defined(__FreeBSD__) || \
    defined(__OpenBSD__) || \
    defined(__NetBSD__)  || \
    defined(BUILD2_AUTOCONF_MACOS)
#  define HAVE_STRUCT_SOCKADDR_SA_LEN 1
#endif

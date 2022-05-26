// HAVE_MMAP : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_MMAP

/* Note: see also HAVE_SYS_MMAN_H. */

/* All versions of glibc, FreeBSD, OpenBSD, NetBSD, and Mac OS (from BSD).
 */
#if defined(__GLIBC__)   || \
    defined(__FreeBSD__) || \
    defined(__OpenBSD__) || \
    defined(__NetBSD__)  || \
    defined(BUILD2_AUTOCONF_MACOS)
#  define HAVE_MMAP 1
#endif

// HAVE_SYS_MMAN_H : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_SYS_MMAN_H

/* Note: see also HAVE_MMAP. */

/* All versions of glibc, FreeBSD, OpenBSD, NetBSD, and Mac OS (from BSD).
 */
#if defined(__GLIBC__)   || \
    defined(__FreeBSD__) || \
    defined(__OpenBSD__) || \
    defined(__NetBSD__)  || \
    defined(BUILD2_AUTOCONF_MACOS)
#  define HAVE_SYS_MMAN_H 1
#endif

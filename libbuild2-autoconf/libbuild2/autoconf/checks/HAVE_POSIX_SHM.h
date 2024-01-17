// HAVE_POSIX_SHM : BUILD2_AUTOCONF_LIBC_VERSION

/* If HAVE_POSIX_SHM is defined then both shm_open() and shm_unlink() are
 * available.
 */

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_POSIX_SHM

/* Since glibc 2.2, FreeBSD 4.3, and NetBSD 7.0.
 *
 * Available on all versions of macOS.
 *
 * Not available on OpenBSD (security concerns).
 *
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 2)   || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(4, 3) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(7, 0)  || \
    defined(BUILD2_AUTOCONF_MACOS)
#  define HAVE_POSIX_SHM 1
#endif

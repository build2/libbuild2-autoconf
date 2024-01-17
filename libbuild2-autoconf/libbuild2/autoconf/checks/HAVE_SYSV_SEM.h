// HAVE_SYSV_SEM : BUILD2_AUTOCONF_LIBC_VERSION

/* If HAVE_SYSV_SEM is defined then all of the SYSV semaphore system calls
 * semget(), semctl(), and semop() are available.
 */

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_SYSV_SEM

/* Since FreeBSD 2.1.0-RELEASE based on checking the online manpages by
 * version.
 *
 * Since OpenBSD 2.2 based on checking the online manpages by version.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 0)     || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(2, 1)   || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199711) || \
    defined(__NetBSD__)                    || \
    defined(BUILD2_AUTOCONF_MACOS)
#  define HAVE_SYSV_SEM 1
#endif

// HAVE_POSIX_SEM : BUILD2_AUTOCONF_LIBC_VERSION

/* If HAVE_POSIX_SEM is defined then all of the POSIX semaphore system calls
 * such as sem_open(), sem_close(), sem_unlink(), etc. are available.
 */

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_POSIX_SEM

/* Since glibc 2.3.3 (when NPTL was added), FreeBSD 3.0, OpenBSD 3.1 (based on
 * checking the online manpages by version), and NetBSD 2.0.
 *
 * Available on all versions of macOS.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 4)     || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(3, 0)   || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(200206) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(2, 0)    || \
    defined(BUILD2_AUTOCONF_MACOS)
#  define HAVE_POSIX_SEM 1
#endif

// HAVE_THREADSAFE_CLOEXEC : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_THREADSAFE_CLOEXEC

/* Define if file descriptor-creating functions taking a *_CLOEXEC flag are
 * available. Setting the FD_CLOEXEC flag in a separate fcntl() call opens a
 * window for another thread to fork/exec.
 *
 * The set of functions covered by this check are pipe2(), dup3(), accept4(),
 * and a version of socket() which takes the SOCK_CLOEXEC flag.
 *
 * Since glibc 2.10, FreeBSD 10, OpenBSD 5.7, NetBSD 6.0.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 10)    || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(10, 0)  || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(201507) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(6, 0)
#  define HAVE_THREADSAFE_CLOEXEC 1
#endif

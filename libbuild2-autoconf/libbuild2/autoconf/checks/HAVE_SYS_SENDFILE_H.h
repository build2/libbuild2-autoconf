// HAVE_SYS_SENDFILE_H : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_SYS_SENDFILE_H

/* Since FreeBSD 3.0, Mac OS 10.5, glibc 2.1
 */
#if defined(__linux__)                     || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(3, 0)   || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 5)    || \
    BUILD2_AUTOCONF_GLIBC_PREREQ(2, 1)
#  define HAVE_SYS_SENDFILE_H 1
#endif

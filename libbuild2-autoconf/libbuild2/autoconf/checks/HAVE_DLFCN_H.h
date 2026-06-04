// HAVE_DLFCN_H : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_DLFCN_H

/* Check for the <dlfcn.h> header.
 *
 * This header is defined by the POSIX.1-2001 (and later) standard.  It
 * declares the dynamic linking functions dlopen(), dlsym(), dlclose(),
 * dlerror(), etc.
 *
 * Available on Linux/glibc, FreeBSD, OpenBSD, NetBSD, and Mac OS (Darwin).
 * Not available on Windows including MinGW.
 *
 * NOTE: a compatibility implementation providing this header and the
 * associated functions is available from the MinGW runtime (mingwrt >= 3.21)
 * or the dlfcn-win32 project.
 */
#if defined(__linux__)              || \
    defined(__FreeBSD__)            || \
    defined(__OpenBSD__)            || \
    defined(__NetBSD__)             || \
    defined(BUILD2_AUTOCONF_MACOS)
#  define HAVE_DLFCN_H 1
#endif

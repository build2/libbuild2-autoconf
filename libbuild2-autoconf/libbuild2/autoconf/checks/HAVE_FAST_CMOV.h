// HAVE_FAST_CMOV : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_FAST_CMOV

/* System has optimized support for Count Leading Zeros (CLZ) instructions.
 * Most modern architectures provide hardware instructions for fast CLZ operations
 * when targeting 64-bit.
 * Since glibc 2.0, FreeBSD 5.0, OpenBSD (x86), NetBSD, MacOS 10.6 (x86_64), Solaris (x86_64 + GCC),
 * Windows, MinGW 3.0
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 3)    || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(5, 0)  || \
    (BUILD2_AUTOCONF_OPENBSD_PREREQ(199610) && defined(__i386__)) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 0) || \
    (BUILD2_AUTOCONF_MACOS_PREREQ(10, 6) && defined(__x86_64__)) || \
    defined(_WIN32) || \
    defined(__MINGW32__) || \
    defined(__CYGWIN__) || \
    (((defined(__sun) && defined(__SVR4)) || defined(__sun__)) && defined(__x86_64__) && defined (__GNUC__))
#  define HAVE_FAST_CMOV 1
#endif

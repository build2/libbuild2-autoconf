// HAVE_FAST_CMOV : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_FAST_CMOV

/* Check for fast Conditional Move (CMOV) support.
 * Fast CMOV is a hardware instruction for conditional data movement.
 *
 * Available on Linux/glibc 2.3, FreeBSD 5.0, OpenBSD (x86), NetBSD, MacOS
 * (exact version is unclear but for a while now), Solaris (x86_64), Windows
 * including MinGW.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 3)                            || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(5, 0)                          || \
    (BUILD2_AUTOCONF_OPENBSD_PREREQ(199610) && defined(__i386__)) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 0)                           || \
    (BUILD2_AUTOCONF_MACOS_PREREQ(10, 6) && defined(__x86_64__))  || \
    defined(_WIN32)                                               || \
    (((defined(__sun) && defined(__SVR4)) || defined(__sun__)) && \
     defined(__x86_64__) && defined(__GNUC__))
#  define HAVE_FAST_CMOV 1
#endif

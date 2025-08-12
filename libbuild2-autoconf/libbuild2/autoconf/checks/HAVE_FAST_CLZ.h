// HAVE_FAST_CLZ : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_FAST_CLZ

/* Check for fast Count Leading Zeros (CLZ) support.
 * Fast CLZ is a hardware instruction for counting leading zeros in an integer.
 *
 * Available on Linux/glibc 2.3, FreeBSD 5.0, OpenBSD, NetBSD, MacOS 10.6,
 * Solaris, Windows including MinGW and Cygwin.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 3)     || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(5, 0)   || \
    BUILD2_AUTOCONF_OPENBSD_PREREQ(199610) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 0)    || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 6)    || \
    defined(_WIN64)                        || \
    defined(__CYGWIN__)                    || \
    ((defined(__sun) && defined(__SVR4)) || defined(__sun__))
#  if defined(__x86_64__)                           || \
      defined(__x86_64)                             || \
      defined(__ppc64__)                            || \
      defined(__PPC64__)                            || \
      defined(__aarch64__)                          || \
      defined(__mips64__)                           || \
      defined(__powerpc64__)                        || \
      defined(__s390x__)                            || \
      (defined(__sparc__) && defined(__arch64__))   || \
      (defined(__riscv_xlen) && __riscv_xlen == 64)
#    define HAVE_FAST_CLZ 1
#  endif
#endif

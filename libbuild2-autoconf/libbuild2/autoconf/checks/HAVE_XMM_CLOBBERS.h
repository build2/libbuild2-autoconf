// HAVE_XMM_CLOBBERS : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_XMM_CLOBBERS

/* Check for XMM register clobber support in assembly.
 * XMM register clobber support allows inline assembly to modify XMM registers
 * used in SSE instructions.
 *
 * Available on Linux/glibc, FreeBSD, OpenBSD, NetBSD, MacOS 10.6, Solaris,
 * Windows including MinGW and Cygwin.
 */
#if defined(__linux__)   || \
    defined(__FreeBSD__) || \
    defined(__OpenBSD__) || \
    defined(__NetBSD__)  || \
    defined(__CYGWIN__)  || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 6) || \
    ((defined(__sun) && defined(__SVR4)) || defined(__sun__))
#  if defined(__SSE__) && defined(__x86_64__)
#    define HAVE_XMM_CLOBBERS 1
#  endif
#endif

// HAVE_XMM_CLOBBERS : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_XMM_CLOBBERS

/* Checks whether the system allows for the use of XMM registers (used in SSE)
 * to be clobbered by inline assembly instructions. It ensures that the
 * compiler knows which registers are being modified.
 * Since Linux, FreeBSD, OpenBSD, NetBSD, MacOS 10.6, Solaris,
 * Windows, MinGW
 */
#if defined(__linux__)                  || \
    defined(__FreeBSD__)                || \
    defined(__OpenBSD__)                || \
    defined(__NetBSD__)                 || \
    defined(__MINGW32__)                || \
    defined(__CYGWIN__)                 || \
    (defined(__sun) && defined(__SVR4)) || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 6)
#  if defined(__SSE__) && defined(__x86_64__)
#    define HAVE_XMM_CLOBBERS 1
#  endif
#endif

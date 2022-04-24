// HAVE_POLL : BUILD2_AUTOCONF_LIBC_VERSION

#undef HAVE_POLL

/* Since Linux 2.1.23/glibc (all versions; emulated using select() on older
 * kernels), FreeBSD (all versions), OpenBSD (all versions), NetBSD 1.3, Mac
 * OS (all versions).
 */
#if defined(__GLIBC__)                  || \
    defined(__FreeBSD__)                || \
    defined(__OpenBSD__)                || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 3) || \
    (defined(__APPLE__) && defined(__MACH__))
#  define HAVE_POLL 1
#endif

// HAVE_ISATTY

#undef HAVE_ISATTY

/* All versions of glibc, FreeBSD, OpenBSD, NetBSD, Mac OS, Windows.
 */
#if defined(__GLIBC__)                      || \
    defined(__FreeBSD__)                    || \
    defined(__OpenBSD__)                    || \
    defined(__NetBSD__)                     || \
    defined(__APPLE__) && defined(__MACH__) || \
    defined(_WIN32)
#  define HAVE_ISATTY 1
#endif

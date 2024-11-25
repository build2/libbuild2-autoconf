// HAVE_CPU_TO_LE64

#undef HAVE_CPU_TO_LE64

/*  Since glibc 2.1, BSD 4.3, FreeBSD 1.0, OpenBSD 2.0, NetBSD 1.0, MacOS, Mingw-w64 2.0
 *  POSIX.1, SVr4
 */
#if defined(__linux__) || \
    defined(__FreeBSD__) || \
    defined(__OpenBSD__) || \
    defined(__NetBSD__)
#  define HAVE_CPU_TO_LE64 1
#endif

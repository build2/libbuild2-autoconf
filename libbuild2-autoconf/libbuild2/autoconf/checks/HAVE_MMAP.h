// HAVE_MMAP

#undef HAVE_MMAP

/* All versions of glibc, FreeBSD, OpenBSD, NetBSD, and Mac OS (from BSD).
 */
#if defined(__GLIBC__)   || \
    defined(__FreeBSD__) || \
    defined(__OpenBSD__) || \
    defined(__NetBSD__)  || \
    defined(__APPLE__) && defined(__MACH__)
#  define HAVE_MMAP 1
#endif

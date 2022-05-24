// HAVE_SYSCONF

#undef HAVE_SYSCONF

#if defined(__linux__)   || \
    defined(__FreeBSD__) || \
    defined(__OpenBSD__) || \
    defined(__NetBSD__)  || \
    (defined(__APPLE__) && defined(__MACH__))
#  define HAVE_SYSCONF 1
#endif

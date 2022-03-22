// HAVE_FCNTL_H

#undef HAVE_FCNTL_H

#if defined(__linux__)   || \
    defined(__FreeBSD__) || \
    defined(__OpenBSD__) || \
    defined(__NetBSD__)  || \
    (defined(__APPLE__) && defined(__MACH__))
#  define HAVE_FCNTL_H 1
#endif

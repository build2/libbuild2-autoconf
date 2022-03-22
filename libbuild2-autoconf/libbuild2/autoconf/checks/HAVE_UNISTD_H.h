// HAVE_UNISTD_H

#undef HAVE_UNISTD_H

#if defined(__linux__)   || \
    defined(__FreeBSD__) || \
    defined(__OpenBSD__) || \
    defined(__NetBSD__)  || \
    (defined(__APPLE__) && defined(__MACH__))
#  define HAVE_UNISTD_H 1
#endif

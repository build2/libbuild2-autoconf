// HAVE_STRLCPY

#undef HAVE_STRLCPY

#if defined(__FreeBSD__) || \
    defined(__OpenBSD__) || \
    defined(__NetBSD__)  || \
    defined(__APPLE__)
#  define HAVE_STRLCPY 1
#endif

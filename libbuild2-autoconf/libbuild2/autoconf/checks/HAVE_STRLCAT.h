// HAVE_STRLCAT
#if defined(__FreeBSD__) || \
    defined(__OpenBSD__) || \
    defined(__NetBSD__)  || \
    defined(__APPLE__)
#  define HAVE_STRLCAT 1
#else
#  undef HAVE_STRLCAT
#endif

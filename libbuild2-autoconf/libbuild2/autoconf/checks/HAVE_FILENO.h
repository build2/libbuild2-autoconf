// HAVE_FILENO

#undef HAVE_FILENO

/* Check for the fileno() function which retrieves the file descriptor
 * associated with a FILE* stream.
 */
#if defined(__GLIBC__)   || \
    defined(__FreeBSD__) || \
    defined(__NetBSD__)  || \
    defined(__OpenBSD__) || \
    defined(__APPLE__)   || \
    defined(_WIN32)
#  define HAVE_FILENO 1
#endif

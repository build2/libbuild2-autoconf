// HAVE_EXPLICIT_BZERO

#undef HAVE_EXPLICIT_BZERO

/* Since FreeBSD 11, OpenBSD 5.5, and glibc 2.25.
 */
#if (defined(__FreeBSD__) && __FreeBSD__ >= 11) ||                      \
    (defined(__OpenBSD__) && defined(OpenBSD) && OpenBSD >= 201405) ||  \
    (defined(__GLIBC__) && defined(__GLIBC_MINOR__) &&                  \
     (__GLIBC__ > 2 || __GLIBC__ == 2 && __GLIBC_MINOR__ >= 25))
#  define HAVE_EXPLICIT_BZERO 1
#endif

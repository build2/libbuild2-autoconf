// HAVE_S_ISREG

#undef HAVE_S_ISREG

/* This checks for the availability of the S_ISREG() macro,
 * which determines if a given file mode indicates a regular
 * file.
 * It is defined in <sys/stat.h> and is part of the POSIX standard.
 */
#if defined(__linux__) || \
    defined(__APPLE__) || \
    defined(__FreeBSD__) || \
    defined(__NetBSD__) || \
    defined(__OpenBSD__) || \
    defined(_WIN32)
#  define HAVE_S_ISREG 1
#endif

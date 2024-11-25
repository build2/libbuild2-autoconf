// HAVE_ISASCII

#undef HAVE_ISASCII

/* Checks for the isascii() macro, which tests if
 * a character is a 7-bit US-ASCII character.
 */
#if defined(__linux__) || \
    defined(__APPLE__) || \
    defined(__FreeBSD__) || \
    defined(__NetBSD__) || \
    defined(__OpenBSD__) || \
    defined(_WIN32)
#  define HAVE_ISASCII 1
#endif

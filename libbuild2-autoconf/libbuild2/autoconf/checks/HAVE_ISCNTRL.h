// HAVE_ISCNTRL

#undef HAVE_ISCNTRL

/* Checks for the iscntrl() function, which tests
 * if a character is a control character.
 */
#if defined(__linux__) || \
    defined(__APPLE__) || \
    defined(__FreeBSD__) || \
    defined(__NetBSD__) || \
    defined(__OpenBSD__) || \
    defined(_WIN32)
#  define HAVE_ISCNTRL 1
#endif

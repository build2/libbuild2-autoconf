// HAVE_DECL_STRLCPY

#undef HAVE_DECL_STRLCPY

/* Checks for the declaration of the strlcpy() function, which
 * safely copies strings with explicit size limits.
 * Commonly available on BSD systems and sometimes ported elsewhere.
 */
#if defined(__FreeBSD__) || \
    defined(__OpenBSD__) || \
    defined(__NetBSD__) || \
    defined(__APPLE__) || \
    defined(__sun) && defined(__SVR4)
#  define HAVE_DECL_STRLCPY 1
#endif

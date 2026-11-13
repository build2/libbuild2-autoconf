// HAVE_EFTYPE

#undef HAVE_EFTYPE

/* Check for the EFTYPE errno code.
 *
 * Only defined on BSDs and Mac OS (including variants like iOS).
 */
#if defined(__FreeBSD__) || \
    defined(__OpenBSD__) || \
    defined(__NetBSD__)  || \
    defined(__APPLE__)
#  define HAVE_EFTYPE 1
#endif

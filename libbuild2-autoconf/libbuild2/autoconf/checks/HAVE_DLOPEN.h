// HAVE_DLOPEN : BUILD2_AUTOCONF_LIBC_VERSION

#undef HAVE_DLOPEN

/* Since Linux/glibc 2.0 and all versions of other supported UNIXes.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 0) || \
    defined(__FreeBSD__)               || \
    defined(__OpenBSD__)               || \
    defined(__NetBSD__)                || \
    (defined(__APPLE__) && defined(__MACH__))
#  define HAVE_DLOPEN 1
#endif

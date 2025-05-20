// HAVE_DECL_STRCASECMP

#undef HAVE_DECL_STRCASECMP

/* Indicates the declaration of strcasecmp() for case-insensitive
 * string comparison, typically in string.h.
 * Since glibc 2.0, BSD, FreeBSD, OpenBSD, NetBSD, MacOS, POSIX.1, SVr4
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 0) || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(1, 0) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 0) || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 0)
#  define HAVE_DECL_STRCASECMP 1
#endif

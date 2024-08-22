// HAVE_BCRYPT : BUILD2_AUTOCONF_LIBC_VERSION

#undef HAVE_BCRYPT

/* Since Version 3 AT&T UNIX, 4.3BSD (OpenBSD), Linux/glibc (no version info)
 */
#if defined(__OpenBSD__) || \
    BUILD2_AUTOCONF_GLIBC_PREREQ(2, 0) || \
    BUILD2_AUTOCONF_MINGW_PREREQ(2, 0)
#  define HAVE_BCRYPT 1
#endif

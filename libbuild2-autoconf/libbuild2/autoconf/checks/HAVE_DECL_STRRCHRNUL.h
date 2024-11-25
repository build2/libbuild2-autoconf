// HAVE_DECL_STRRCHRNUL : BUILD2_AUTOCONF_LIBC_VERSION

#undef HAVE_DECL_STRRCHRNUL

/* This checks for the declaration of the strnlen() function, which
 * calculates the length of a string up to a specified maximum number
 * of characters.
 * It is part of the POSIX standard but not universally available.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 2)
#  define HAVE_DECL_STRRCHRNUL 1
#endif

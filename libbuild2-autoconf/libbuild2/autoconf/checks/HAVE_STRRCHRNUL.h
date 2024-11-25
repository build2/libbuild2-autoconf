// HAVE_STRRCHRNUL : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_STRRCHRNUL

/* Checks for the GNU extension strrchrnul(), which locates the last
 * occurrence of a character in a string and returns a pointer to it
 * or to the null byte.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 2)
#  define HAVE_STRRCHRNUL 1
#endif

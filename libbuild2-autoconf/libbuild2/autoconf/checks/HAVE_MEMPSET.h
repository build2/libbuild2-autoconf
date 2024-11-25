// HAVE_MEMPSET : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_MEMPSET

/* Checks for the presence of a mempset() function, which would
 * be used for memory operations similar to memset() but with
 * additional pointer handling.
 * This function is not widely available and is often a
 * placeholder for a GNU extension.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 36)
#  define HAVE_MEMPSET 1
#endif

// HAVE__DL_FIND_OBJECT : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE__DL_FIND_OBJECT

/* Check for _dl_find_object() in <dlfcn.h>.
 *
 * Added in glibc 2.35. Not available on Mac OS, Windows, or MinGW.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 35)
#  define HAVE__DL_FIND_OBJECT 1
#endif

// HAVE_DLADDR1 : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_DLADDR1

/* Check for dladdr1() in <dlfcn.h>.
 *
 * Available in glibc since 2.3.3. Not available on Mac OS (different dladdr
 * behavior) or Windows.
 *
 * NOTE: Only defined for glibc < 2.35 (the preferred interface thereafter
 * is _dl_find_object()).
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 3) && !BUILD2_AUTOCONF_GLIBC_PREREQ(2, 35)
#  define HAVE_DLADDR1 1
#endif

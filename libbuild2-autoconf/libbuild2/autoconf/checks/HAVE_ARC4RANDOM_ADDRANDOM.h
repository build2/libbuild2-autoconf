// HAVE_ARC4RANDOM_ADDRANDOM : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_ARC4RANDOM_ADDRANDOM

/* Since NetBSD 2.0.
 *
 * It was removed from OpenBSD in version 5.5 because it 'should not be called
 * directly' so treat it as not present in any version.
 */
#if BUILD2_AUTOCONF_NETBSD_PREREQ(2, 0)
#  define HAVE_ARC4RANDOM_ADDRANDOM 1
#endif

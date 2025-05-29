// HAVE_SYSCTLBYNAME : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_SYSCTLBYNAME

/* Presence of the sysctlbyname() function, which retrieves system
 * information using a string name (e.g., hardware data or OS settings).
 * It's commonly used in BSD-based systems to access system configuration parameters.
 * Since FreeBSD 2.2, NetBSD 1.3, MacOS 10.0
 */
#if BUILD2_AUTOCONF_FREEBSD_PREREQ(2, 2) || \
    BUILD2_AUTOCONF_NETBSD_PREREQ(1, 3) || \
    BUILD2_AUTOCONF_MACOS_PREREQ(10, 0)
#  define HAVE_SYSCTLBYNAME 1
#endif

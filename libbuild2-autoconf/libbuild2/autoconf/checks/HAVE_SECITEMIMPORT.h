// HAVE_SECITEMIMPORT : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_SECITEMIMPORT

/* Presence of the SecItemImport function, which is used in Apple's
 * Security framework for importing security items (such as certificates or keys).
 * Since MacOS 10.7/iOS 5
 */
#if BUILD2_AUTOCONF_MACOS_PREREQ(10, 7)
#  define HAVE_SECITEMIMPORT 1
#endif

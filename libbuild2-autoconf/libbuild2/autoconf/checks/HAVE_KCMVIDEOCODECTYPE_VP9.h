// HAVE_KCMVIDEOCODECTYPE_VP9 : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_KCMVIDEOCODECTYPE_VP9

/* VP9 codec, an open-source codec developed by Google.
 * Since MacOS 10.15/iOS 13
 */
#if BUILD2_AUTOCONF_MACOS_PREREQ(10, 15)
#  define HAVE_KCMVIDEOCODECTYPE_VP9 1
#endif

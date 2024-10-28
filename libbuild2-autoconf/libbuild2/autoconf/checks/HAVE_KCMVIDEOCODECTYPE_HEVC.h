// HAVE_KCMVIDEOCODECTYPE_HEVC : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_KCMVIDEOCODECTYPE_HEVC

/* HEVC (High-Efficiency Video Coding),
 * also known as H.265 codec, in the media framework.
 * Since MacOS 10.13/iOS 11
 */
#if BUILD2_AUTOCONF_MACOS_PREREQ(10, 13)
#  define HAVE_KCMVIDEOCODECTYPE_HEVC 1
#endif

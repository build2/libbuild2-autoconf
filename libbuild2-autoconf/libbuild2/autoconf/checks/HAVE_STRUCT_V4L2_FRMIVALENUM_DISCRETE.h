// HAVE_STRUCT_V4L2_FRMIVALENUM_DISCRETE : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_STRUCT_V4L2_FRMIVALENUM_DISCRETE

/* Check for the v4l2_frmivalenum discrete structure.
 * v4l2_frmivalenum is a Video4Linux2 (V4L2) API structure that specifies
 * discrete frame intervals for video devices.
 *
 * Available on Linux/glibc 2.5. Not available on Windows or MacOS.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 5)
#  define HAVE_STRUCT_V4L2_FRMIVALENUM_DISCRETE 1
#endif

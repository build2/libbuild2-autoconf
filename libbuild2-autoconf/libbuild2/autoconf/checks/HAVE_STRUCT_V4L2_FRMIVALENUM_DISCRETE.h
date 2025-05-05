// HAVE_STRUCT_V4L2_FRMIVALENUM_DISCRETE : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_STRUCT_V4L2_FRMIVALENUM_DISCRETE

/* Presence of the v4l2_frmivalenum structure, specifically for
 * discrete frame intervals, in the Video4Linux2 (V4L2) API.
 * Since glibc 2.5
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 5)
#  define HAVE_STRUCT_V4L2_FRMIVALENUM_DISCRETE 1
#endif

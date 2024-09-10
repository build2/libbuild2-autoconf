// HAVE_LIBDRM_GETFB2

#undef HAVE_LIBDRM_GETFB2

/* Presence of the libdrm's getfb2() function, which is part of
 * Direct Rendering Manager (DRM) used for managing graphics on Linux.
 * Linux (libdrm 2.4.91)
 */
#if defined(__linux__)
#  include <drm/drm.h>
#  ifdef DRM_IOCTL_MODE_GETFB2
#    define HAVE_LIBDRM_GETFB2 1
#  endif
#endif

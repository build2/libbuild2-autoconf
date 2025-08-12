// HAVE_MMAL_PARAMETER_VIDEO_MAX_NUM_CALLBACKS

#undef HAVE_MMAL_PARAMETER_VIDEO_MAX_NUM_CALLBACKS

/* Check for the MMAL_PARAMETER_VIDEO_MAX_NUM_CALLBACKS parameter.
 * MMAL_PARAMETER_VIDEO_MAX_NUM_CALLBACKS is a Multimedia Abstraction Layer
 * parameter for managing video callbacks on Raspberry Pi platforms.
 *
 * Available on Linux/glibc, Raspberry Pi (exact version is unclear but for a
 * while now). Not available on Windows or MacOS.
 */
#ifdef MMAL_PARAMETER_VIDEO_MAX_NUM_CALLBACKS
#  define HAVE_MMAL_PARAMETER_VIDEO_MAX_NUM_CALLBACKS 1
#endif

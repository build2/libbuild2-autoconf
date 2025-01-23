// HAVE_MMAL_PARAMETER_VIDEO_MAX_NUM_CALLBACKS

#undef HAVE_MMAL_PARAMETER_VIDEO_MAX_NUM_CALLBACKS

/* Presence of the MMAL (Multimedia Abstraction Layer) parameter
 * MMAL_PARAMETER_VIDEO_MAX_NUM_CALLBACKS, used for managing video
 * callbacks on Raspberry Pi and similar platforms.
 * Since Raspberry Pi (2013), predefined by MMAL
 */
#ifdef MMAL_PARAMETER_VIDEO_MAX_NUM_CALLBACKS
#  define HAVE_MMAL_PARAMETER_VIDEO_MAX_NUM_CALLBACKS 1
#endif

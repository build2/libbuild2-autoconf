// HAVE_SETMODE

#undef HAVE_SETMODE

/* Presence of the setmode() function, used to set the mode
 * of a file descriptor (such as binary or text mode).
 * Windows, MingW
 */
#if defined(_WIN32) || defined(__MINGW32__)
#  define HAVE_SETMODE 1
#endif

// HAVE_SYS_UTIME_H

#undef HAVE_SYS_UTIME_H

/* Check for the sys/utime.h header.
 *
 * Only available on Windows.
 */
#if defined(_WIN32)
#  define HAVE_SYS_UTIME_H 1
#endif

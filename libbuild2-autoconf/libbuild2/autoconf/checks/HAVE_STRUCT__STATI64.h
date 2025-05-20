// HAVE_STRUCT__STATI64

#undef HAVE_STRUCT__STATI64

/* Checks for the _stati64 structure, used in 64-bit
 * file handling on Windows platforms.
 */
#if defined(_WIN32)
#  define HAVE_STRUCT__STATI64 1
#endif

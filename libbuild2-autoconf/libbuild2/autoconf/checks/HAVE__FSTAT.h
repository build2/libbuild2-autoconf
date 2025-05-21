// HAVE__FSTAT

#undef HAVE__FSTAT

/* Check for the Windows-specific _fstat() function which retrieves file
 * information using a file descriptor.
 */
#if defined(_WIN32) || defined(__MINGW32__)
#  define HAVE__FSTAT 1
#endif

// HAVE__FSTAT64

#undef HAVE__FSTAT64

/* Check for the Windows-specific _fstat64() function which retrieves file
 * status information for a file descriptor using a 64-bit structure. It
 * supports large files and is equivalent to fstat() in POSIX environments for
 * handling 64-bit file sizes.
 */
#if defined(_WIN32) || defined(__MINGW32__)
#  define HAVE__FSTAT64 1
#endif

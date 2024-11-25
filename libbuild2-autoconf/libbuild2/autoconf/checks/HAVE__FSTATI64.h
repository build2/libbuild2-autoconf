// HAVE__FSTATI64

#undef HAVE__FSTATI64

/* checks for the availability of _fstati64(), a
 * Microsoft-specific function that retrieves
 * file status information for a file descriptor
 * using a 64-bit structure. It supports large
 * files and is equivalent to fstat() in POSIX
 * environments for handling 64-bit file sizes.
 */
#if defined(_WIN32) || defined(__MINGW32__)
#  define HAVE__FSTATI64 1
#endif

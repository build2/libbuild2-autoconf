// HAVE__STATI64

#undef HAVE__STATI64

/* Checks for the availability of _stati64(), a
 * Microsoft-specific function that retrieves
 * file status information using a 64-bit structure
 * for large file support.
 * It is the Windows equivalent of stat() in POSIX
 * systems, extended to support 64-bit file sizes.
 */
#if defined(_WIN32) || defined(__MINGW32__)
#  define HAVE__STATI64 1
#endif

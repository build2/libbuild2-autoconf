// HAVE__FSEEKI64

#undef HAVE__FSEEKI64

/* Checks for the availability of _fseeki64(), a
 * Microsoft-specific function that moves the file
 * position indicator for a file stream using a
 * 64-bit integer offset.
 * It is the Windows equivalent of fseeko() in
 * POSIX environments and supports large files.
 */
#if defined(_WIN32) || defined(__MINGW32__)
#  define HAVE__FSEEKI64 1
#endif

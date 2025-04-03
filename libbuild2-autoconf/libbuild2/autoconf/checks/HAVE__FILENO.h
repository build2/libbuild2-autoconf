// HAVE__FILENO

#undef HAVE__FILENO

/* Checks for the availability of _fileno(),
 * a Microsoft-specific function that retrieves the
 * file descriptor associated with a FILE* stream.
 * It is the Windows equivalent of the fileno()
 * function in POSIX environments.
 */
#if defined(_WIN32) || defined(__MINGW32__)
#  define HAVE__FILENO 1
#endif

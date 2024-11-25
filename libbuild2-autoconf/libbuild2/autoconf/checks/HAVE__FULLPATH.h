// HAVE__FULLPATH

#undef HAVE__FULLPATH

/* Checks for the availability of the _fullpath()
 * function, a Microsoft-specific function that
 * converts a relative file path to an absolute
 * path.
 * It is equivalent to realpath() in POSIX systems
 * but is specific to Windows environments.
 */
#if defined(_WIN32) || defined(__MINGW32__)
#  define HAVE__FULLPATH 1
#endif

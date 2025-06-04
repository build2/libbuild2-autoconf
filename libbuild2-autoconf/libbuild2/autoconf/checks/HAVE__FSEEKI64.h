// HAVE__FSEEKI64

#undef HAVE__FSEEKI64

/* Checks for the availability of _fseeki64(), a
 * Microsoft-specific function that moves the file
 * position indicator for a file stream using a
 * 64-bit integer offset.
 * - Available on MSVC since Visual Studio 2005 (_MSC_VER >= 1400)
 * - Available on MinGW (with MSVCRT runtime) when targeting Windows
 * - Not available on POSIX or other non-Windows environments.
 */

#if (defined(_WIN32) && defined(_MSC_VER) && (_MSC_VER >= 1400)) || \
    (defined(__MINGW32__) && !defined(__CYGWIN__))
#  define HAVE__FSEEKI64 1
#endif

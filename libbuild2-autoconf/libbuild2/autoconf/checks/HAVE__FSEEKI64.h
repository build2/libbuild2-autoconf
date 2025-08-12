// HAVE__FSEEKI64

#undef HAVE__FSEEKI64

/* Check for the _fseeki64() function.
 * _fseeki64() is a Microsoft-specific function that moves the file position
 * indicator for a file stream using a 64-bit integer offset.
 *
 * Available on Windows including MinGW. Not available on Linux/glibc or MacOS.
 * Requires MSVC with Visual Studio 2005 (_MSC_VER >= 1400) or later, or MinGW
 * with MSVCRT runtime (not Cygwin).
 */
#if (defined(_WIN32) && defined(_MSC_VER) && (_MSC_VER >= 1400)) || \
    (defined(__MINGW32__) && !defined(__CYGWIN__))
#  define HAVE__FSEEKI64 1
#endif

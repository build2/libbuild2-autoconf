// HAVE_SETCONSOLETEXTATTRIBUTE

#undef HAVE_SETCONSOLETEXTATTRIBUTE

/* Check for the SetConsoleTextAttribute() function.
 *
 * Available on Windows including MinGW. Not available on Linux/glibc or MacOS.
 */
#if defined(_WIN32)
#  define HAVE_SETCONSOLETEXTATTRIBUTE 1
#endif

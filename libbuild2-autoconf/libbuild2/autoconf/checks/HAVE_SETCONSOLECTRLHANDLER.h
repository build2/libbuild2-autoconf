// HAVE_SETCONSOLECTRLHANDLER

#undef HAVE_SETCONSOLECTRLHANDLER

/* Check for the SetConsoleCtrlHandler() function.
 *
 * Available on Windows including MinGW. Not available on Linux/glibc or MacOS.
 */
#if defined(_WIN32)
#  define HAVE_SETCONSOLECTRLHANDLER 1
#endif

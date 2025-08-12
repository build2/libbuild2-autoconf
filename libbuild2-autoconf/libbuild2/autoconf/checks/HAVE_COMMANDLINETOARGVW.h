// HAVE_COMMANDLINETOARGVW

#undef HAVE_COMMANDLINETOARGVW

/* Check for the CommandLineToArgvW() function.
 *
 * Available on Windows including MinGW. Not available on Linux/glibc or MacOS.
 */
#if defined(_WIN32)
#  define HAVE_COMMANDLINETOARGVW 1
#endif

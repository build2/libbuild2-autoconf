// HAVE_SETCONSOLECTRLHANDLER

#undef HAVE_SETCONSOLECTRLHANDLER

/* Presence of the SetConsoleCtrlHandler() function, which is specific
 * to Windows for handling console control events like Ctrl+C.
 * Windows
 */
#if defined(_WIN32)
#  define HAVE_SETCONSOLECTRLHANDLER 1
#endif

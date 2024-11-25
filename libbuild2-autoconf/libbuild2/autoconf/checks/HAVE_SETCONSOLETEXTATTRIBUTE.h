// HAVE_SETCONSOLETEXTATTRIBUTE

#undef HAVE_SETCONSOLETEXTATTRIBUTE

/* Presence of the SetConsoleTextAttribute() function, which is used
 * on Windows to change the text color and attributes in the console.
 * Windows
 */
#if defined(_WIN32)
#  define HAVE_SETCONSOLETEXTATTRIBUTE 1
#endif

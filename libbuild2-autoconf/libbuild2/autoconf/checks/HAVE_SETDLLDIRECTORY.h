// HAVE_SETDLLDIRECTORY

#undef HAVE_SETDLLDIRECTORY

/* Presence of the SetDllDirectory() function, which sets a
 * directory to search for DLLs when loading libraries in Windows.
 * Windows
 */
#if defined(_WIN32)
#  define HAVE_SETDLLDIRECTORY 1
#endif

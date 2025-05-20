// HAVE_COMMANDLINETOARGVW

#undef HAVE_COMMANDLINETOARGVW

/* Windows, Mingw
 */
#if defined(_WIN32) || \
    defined(__MINGW32__)
#  define HAVE_COMMANDLINETOARGVW 1
#endif

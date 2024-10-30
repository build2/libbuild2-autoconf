// HAVE_GNU_WINDRES

#undef HAVE_GNU_WINDRES

/* GNU windres is commonly available in MinGW and Cygwin environments,
 * where it's used to compile Windows resource files (.rc).
 */
#if defined(__MINGW32__) || defined(__MINGW64__) || defined(__CYGWIN__)
    #define HAVE_GNU_WINDRES 1
#endif

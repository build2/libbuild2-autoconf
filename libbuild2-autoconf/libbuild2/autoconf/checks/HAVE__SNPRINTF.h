// HAVE__SNPRINTF

#undef HAVE__SNPRINTF

/* This checks for the Windows-specific _snprintf() function, which safely
 * formats strings into a buffer.
 */
#if defined(_WIN32) || defined(__MINGW32__)
#  define HAVE__SNPRINTF 1
#endif

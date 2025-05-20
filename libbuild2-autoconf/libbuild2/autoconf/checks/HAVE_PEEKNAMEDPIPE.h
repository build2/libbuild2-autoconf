// HAVE_PEEKNAMEDPIPE

#undef HAVE_PEEKNAMEDPIPE

/* Presence of OS/2 threads support,
 * specific to the OS/2 operating system.
 */
#ifdef _WIN32
#  define HAVE_PEEKNAMEDPIPE 1
#endif

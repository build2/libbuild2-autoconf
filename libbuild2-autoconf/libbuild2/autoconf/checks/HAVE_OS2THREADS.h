// HAVE_OS2THREADS

#undef HAVE_OS2THREADS

/* Presence of OS/2 threads support,
 * specific to the OS/2 operating system.
 */
#ifdef __OS2__
#  define HAVE_OS2THREADS 1
#endif

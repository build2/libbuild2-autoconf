// HAVE_IO_H

#undef HAVE_IO_H

/* Checks for the io.h header, which declares functions like _open,
 * _close, and _read.
 * Typically used in Windows environments.
 */
#if defined(_WIN32)
#  define HAVE_IO_H 1
#endif

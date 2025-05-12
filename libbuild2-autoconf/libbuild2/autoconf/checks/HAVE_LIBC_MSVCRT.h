// HAVE_LIBC_MSVCRT

#undef HAVE_LIBC_MSVCRT

/*  Presence of MSVCRT (Microsoft Visual C++ Runtime Library) in the C standard library.
 */
#if defined(_MSC_VER)
#  define HAVE_LIBC_MSVCRT 1
#endif

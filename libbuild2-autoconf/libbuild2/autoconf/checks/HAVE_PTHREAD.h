// HAVE_PTHREAD

/* Note that MinGW-W64 has pthread in the form of the libwinpthreads wrapper
   (though GCC may or may not be configured to use pthread). However, it's
   probably not a good idea to define this macro for MinGW-W64 since this
   may cause whomever depends on this check to use the wrapper instead of
   the native Win32 threads support. */

#undef HAVE_PTHREAD

#ifndef _WIN32
#  define HAVE_PTHREAD 1
#endif

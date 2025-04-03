// size_t!

/* If size_t is already defined, assume it's correct and use it as-is.
 *
 * Note that we may not be able to redefine it because while we can undef the
 * macro, there is no guarantee we will be able to re-include the header (due
 * to include guards).
 */
#ifndef size_t
  /* POSIX and MinGW (which also has <sys/types.h> that defines size_t).
   */
#  if defined(__linux__)                  || \
      defined(__FreeBSD__)                || \
      defined(__OpenBSD__)                || \
      defined(__NetBSD__)                 || \
      defined(__APPLE__)                  || \
      defined(__MINGW32__)                || \
      (defined(__sun) && defined(__SVR4)) || \
      defined(__CYGWIN__)
#    include <sys/types.h>
     /* If available, we do nothing. */
#  elif defined(_WIN32)
#    include <basetsd.h>
     /* Use define instead of typedef to avoid conflicts. */
#    define size_t SIZE_T
#  else
     /* Else define it to int (suggested fallback by libevent). */
#    define size_t unsigned int
#  endif
#endif

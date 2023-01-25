// HAVE_POSIX_MONOTONIC

#undef HAVE_POSIX_MONOTONIC

#if defined(__GLIBC__)             || \
    defined(__FreeBSD__)           || \
    defined(__OpenBSD__)           || \
    defined(__NetBSD__)            || \
    defined(BUILD2_AUTOCONF_MACOS) || \
    defined(__MINGW32__)
#  include <unistd.h> /* _POSIX_MONOTONIC_CLOCK */

  /* A value of 0 means it's supported for compilation while a value greater
   * than 0 means it's supported for compilation and at runtime (see
   * https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/unistd.h.html).
   */
#  if defined(_POSIX_MONOTONIC_CLOCK) && _POSIX_MONOTONIC_CLOCK >= 0
#    define HAVE_POSIX_MONOTONIC 1
#  endif
#endif

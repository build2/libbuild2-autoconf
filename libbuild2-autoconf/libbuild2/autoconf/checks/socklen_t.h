// socklen_t! : BUILD2_AUTOCONF_LIBC_VERSION

/* If socklen_t is already defined, assume it's correct and use it as-is (see
 * ssize_t for details).
 */
#ifndef socklen_t

/* Since 4.xBSD, SunOS
 * The Single UNIX Specification, Version 2
 *   <sys/socket.h> makes available a type, socklen_t, which is
 *   an unsigned opaque integral type of length of at least 32 bits.
 *   To forestall portability problems, it is recommended that
 *   applications should not use values larger than 232 - 1.
 */
#  if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 0) || \
      BUILD2_AUTOCONF_FREEBSD_PREREQ(4, 0) || \
      BUILD2_AUTOCONF_OPENBSD_PREREQ(199510) || \
      BUILD2_AUTOCONF_NETBSD_PREREQ(1, 0) || \
      BUILD2_AUTOCONF_MACOS_PREREQ(10, 0) || \
      (defined(__sun) && defined(__SVR4)) || \
      defined(__CYGWIN__)
#     include <sys/socket.h>
      /* If available, we do nothing. */
#  elif defined(_WIN32)
      /* While socklen_t is declared in <ws2tcpip.h>, including this header is
       * hazardous due to it being sensitive to WIN32_LEAN_AND_MEAN (and who
       * knows what else). At the same time, in both Platform SDK and MinGW,
       * this is a simple int typedef and so just doing that feels like the
       * simplest (if hackish) way to sidestep the whole mess.
       */
       typedef int socklen_t;
#  else
      /* Else define it to unsigned int (suggested fallback by libevent). */
#     define socklen_t unsigned int
#  endif
#endif

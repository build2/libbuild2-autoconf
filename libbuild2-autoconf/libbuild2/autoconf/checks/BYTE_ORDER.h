// BYTE_ORDER!

/* Define BYTE_ORDER, BIG_ENDIAN, and LITTLE_ENDIAN macros.
 *
 * Note that GCC (since 4.6) and Clang (since 3.1) provide predefined macros
 * __BYTE_ORDER__, __ORDER_BIG_ENDIAN__, and __ORDER_LITTLE_ENDIAN__. Prefer
 * these macros, if available. Otherwise, use the platform-specific headers
 * for POSIX systems and provide custom macro definitions on Windows.
 */
#if !defined(BYTE_ORDER)
#  if defined(__BYTE_ORDER__)       && \
      defined(__ORDER_BIG_ENDIAN__) && \
      defined(__ORDER_LITTLE_ENDIAN__)
#    define BYTE_ORDER    __BYTE_ORDER__
#    define BIG_ENDIAN    __ORDER_BIG_ENDIAN__
#    define LITTLE_ENDIAN __ORDER_LITTLE_ENDIAN__
#  else
    /* Note that these headers normally define BYTE_ORDER, LITTLE_ENDIAN, and
     * BIG_ENDIAN. However, they can be affected by feature macros like
     * _ANSI_SOURCE, _POSIX_C_SOURCE, _XOPEN_SOURCE, or _NETBSD_SOURCE,
     * depending on the platform. In such cases they may define the
     * underscored versions only.
     */
#    if defined(__GLIBC__) || defined(__OpenBSD__)
      /* POSIX header. Available on Linux, FreeBSD, but not MacOS.
       */
#      include <endian.h>
#    elif defined(__FreeBSD__) || defined(__NetBSD__)
       /* Not a POSIX header. Normally available on BSD-derived systems, in
        * particular, on FreeBSD but not MacOS.
        */
#      include <sys/endian.h>
#    elif defined(__APPLE__)
       /* Not a POSIX header. Normally available on BSD-derived systems, in
        * particular, on FreeBSD and MacOS.
        */
#      include <machine/endian.h>
#    elif !defined(_WIN32)
       /* Not a POSIX header. Normally available on POSIX systems, in
        * particular, on Linux, FreeBSD, and MacOS.
        */
#      include <sys/param.h>
#    endif

    /* If the endianness headers did not define BYTE_ORDER, then try various
     * system-specific byte order macro names.
     */
#    if !defined(BYTE_ORDER)
#      if defined(__linux__)
#        if defined(__BYTE_ORDER)
#          define BYTE_ORDER    __BYTE_ORDER
#          define BIG_ENDIAN    __BIG_ENDIAN
#          define LITTLE_ENDIAN __LITTLE_ENDIAN
#        endif
#      elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
#        if defined(_BYTE_ORDER)
#          define BYTE_ORDER    _BYTE_ORDER
#          define BIG_ENDIAN    _BIG_ENDIAN
#          define LITTLE_ENDIAN _LITTLE_ENDIAN
#        endif
#      elif defined(__APPLE__)
#        if defined(__DARWIN_BYTE_ORDER)
#          define BYTE_ORDER    __DARWIN_BYTE_ORDER
#          define BIG_ENDIAN    __DARWIN_BIG_ENDIAN
#          define LITTLE_ENDIAN __DARWIN_LITTLE_ENDIAN
#        endif
#      elif defined(_WIN32)
#        define BIG_ENDIAN    4321
#        define LITTLE_ENDIAN 1234
#        define BYTE_ORDER    LITTLE_ENDIAN
#      endif
#    endif
#  endif
#endif

#ifndef BYTE_ORDER
#  error no byte order macros defined
#endif

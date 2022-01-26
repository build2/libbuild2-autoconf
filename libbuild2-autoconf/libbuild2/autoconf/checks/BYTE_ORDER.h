// BYTE_ORDER!

/* Include the endianness header based on platform.
 *
 * Each of these headers should define BYTE_ORDER, LITTLE_ENDIAN, BIG_ENDIAN,
 * AND PDP_ENDIAN but this can be affected by macros like _ANSI_SOURCE,
 * _POSIX_C_SOURCE, _XOPEN_SOURCE and _NETBSD_SOURCE, depending on the
 * platform (in which case most of them define underscored versions only).
 */
#if defined(__GLIBC__) || defined(__OpenBSD__)
#  include <endian.h>
#elif defined(__FreeBSD__) || defined(__NetBSD__)
#  include <sys/endian.h>
#elif defined(__APPLE__)
#  include <machine/endian.h>
#elif !defined(_WIN32)
#  include <sys/param.h>
#endif

/* Try various system- and compiler-specific byte order macro names if the
 * endianness headers did not define BYTE_ORDER.
 */
#if !defined(BYTE_ORDER)
#  if defined(__linux__)
#    if defined(__BYTE_ORDER)
#      define BYTE_ORDER    __BYTE_ORDER
#      define BIG_ENDIAN    __BIG_ENDIAN
#      define LITTLE_ENDIAN __LITTLE_ENDIAN
#    endif
#  elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
#    if defined(_BYTE_ORDER)
#      define BYTE_ORDER    _BYTE_ORDER
#      define BIG_ENDIAN    _BIG_ENDIAN
#      define LITTLE_ENDIAN _LITTLE_ENDIAN
#    endif
#  elif defined(__APPLE__)
#    if defined(__DARWIN_BYTE_ORDER)
#      define BYTE_ORDER    __DARWIN_BYTE_ORDER
#      define BIG_ENDIAN    __DARWIN_BIG_ENDIAN
#      define LITTLE_ENDIAN __DARWIN_LITTLE_ENDIAN
#    endif
#  elif defined(_WIN32)
#    define BIG_ENDIAN    4321
#    define LITTLE_ENDIAN 1234
#    define BYTE_ORDER    LITTLE_ENDIAN
#  elif defined(__BYTE_ORDER__) &&       \
        defined(__ORDER_BIG_ENDIAN__) && \
        defined(__ORDER_LITTLE_ENDIAN__)
     /* GCC, Clang (and others, potentially).
      */
#    define BYTE_ORDER    __BYTE_ORDER__
#    define BIG_ENDIAN    __ORDER_BIG_ENDIAN__
#    define LITTLE_ENDIAN __ORDER_LITTLE_ENDIAN__
#  endif
#endif

#ifndef BYTE_ORDER
#  error no byte order macros defined
#endif

// BYTE_ORDER!

/* Detect BYTE_ORDER/BIG_ENDIAN/LITTLE_ENDIAN
 * Prefer compiler built-ins first, then common headers, with a Windows
 * little-endian fallback. Some platforms gate macro visibility behind
 * feature macros like _ANSI_SOURCE, _POSIX_C_SOURCE, _XOPEN_SOURCE, or
 * _NETBSD_SOURCE; in those cases headers may only expose underscored
 * forms (e.g., __BYTE_ORDER or _BYTE_ORDER). This code aliases those to
 * the non-underscored names when found.
 *
 * Available on OpenBSD 2.0, FreeBSD 3.0, NetBSD 1.3, macOS 10.0,
 * Linux/glibc 2.0, Solaris 10, and Windows including MinGW & Cygwin.
 */

// endian detection — prefer compiler built-ins, then headers, then
// Windows fallback.
#ifndef BYTE_ORDER
   // 1) Compiler built-ins (GCC/Clang)
#  if defined(__BYTE_ORDER__)       && \
      defined(__ORDER_BIG_ENDIAN__) && \
      defined(__ORDER_LITTLE_ENDIAN__)
#    define BYTE_ORDER     __BYTE_ORDER__
#    define BIG_ENDIAN     __ORDER_BIG_ENDIAN__
#    define LITTLE_ENDIAN  __ORDER_LITTLE_ENDIAN__
   // 2) Try common headers if present
#  elif defined(__has_include)
#    if __has_include(<endian.h>)
#      include <endian.h>
#    elif __has_include(<sys/endian.h>)
#      include <sys/endian.h>
#    elif __has_include(<machine/endian.h>)
       // NOTE: This header is deprecated on macOS and can pollute the
       //       namespace (e.g., u_int). It should not be necessary in
       //       practice; included only as a last resort.
#      include <machine/endian.h>
#    elif !defined(_WIN32) && __has_include(<sys/param.h>)
#      include <sys/param.h>
#    endif
#  endif

   // 3) If headers gave us underscored names, alias them.
#  if !defined(BYTE_ORDER)
#    if defined(__BYTE_ORDER) && \
        defined(__BIG_ENDIAN) && \
        defined(__LITTLE_ENDIAN)
#      define BYTE_ORDER     __BYTE_ORDER
#      define BIG_ENDIAN     __BIG_ENDIAN
#      define LITTLE_ENDIAN  __LITTLE_ENDIAN
#    elif defined(_BYTE_ORDER) && \
          defined(_BIG_ENDIAN) && \
          defined(_LITTLE_ENDIAN)
#      define BYTE_ORDER     _BYTE_ORDER
#      define BIG_ENDIAN     _BIG_ENDIAN
#      define LITTLE_ENDIAN  _LITTLE_ENDIAN
#    elif defined(__DARWIN_BYTE_ORDER) && \
          defined(__DARWIN_BIG_ENDIAN) && \
          defined(__DARWIN_LITTLE_ENDIAN)
#      define BYTE_ORDER     __DARWIN_BYTE_ORDER
#      define BIG_ENDIAN     __DARWIN_BIG_ENDIAN
#      define LITTLE_ENDIAN  __DARWIN_LITTLE_ENDIAN
#    endif
#  endif
   // 4) Windows (MSVC/MinGW/ClangCL) — all support Windows ABIs & are LE.
#  if !defined(BYTE_ORDER) && defined(_WIN32)
#    define BIG_ENDIAN     4321
#    define LITTLE_ENDIAN  1234
#    define BYTE_ORDER     LITTLE_ENDIAN
#  endif
#endif

#ifndef BYTE_ORDER
#  error no byte order macros defined
#endif

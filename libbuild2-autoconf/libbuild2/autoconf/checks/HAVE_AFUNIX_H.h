// HAVE_AFUNIX_H

#undef HAVE_AFUNIX_H

/* Note that __MINGW32_*_VERSION seems to be frozen and so cannot be used
 * for this check. Which means this header is never available on 32-bit
 * MinGW.
 */

#ifdef _MSC_VER
#  include <sdkddkver.h>
#  if defined(WDK_NTDDI_VERSION) && WDK_NTDDI_VERSION >= NTDDI_WIN10_19H1
#    define HAVE_AFUNIX_H 1
#  endif
#elif defined(__MINGW64__)
#  include <stddef.h>
#  if defined(__MINGW64_MAJOR_VERSION) && __MINGW64_MAJOR_VERSION >= 11
#    define HAVE_AFUNIX_H 1
#  endif
#endif

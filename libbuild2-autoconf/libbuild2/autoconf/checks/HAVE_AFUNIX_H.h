// HAVE_AFUNIX_H : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_AFUNIX_H

#ifdef _MSC_VER
#  include <sdkddkver.h>
#  if defined(WDK_NTDDI_VERSION) && WDK_NTDDI_VERSION >= NTDDI_WIN10_19H1
#    define HAVE_AFUNIX_H 1
#  endif
#elif BUILD2_AUTOCONF_MINGW_PREREQ(11, 0)
#  define HAVE_AFUNIX_H 1
#endif

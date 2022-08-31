// HAVE_AFUNIX_H

#undef HAVE_AFUNIX_H

#ifdef _MSC_VER
#include <sdkddkver.h>
#endif

#if defined(__MINGW32__) && __MINGW32_MAJOR_VERSION >= 11 || \
    defined(__MINGW64__) && __MINGW64_VERSION_MAJOR >= 11 || \
    defined(_MSC_VER) && defined(WDK_NTDDI_VERSION) && \
    WDK_NTDDI_VERSION >= NTDDI_WIN10_19H1
#define HAVE_AFUNIX_H 1
#endif

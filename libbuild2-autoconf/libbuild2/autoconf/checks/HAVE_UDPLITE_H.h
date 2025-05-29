// HAVE_UDPLITE_H

#undef HAVE_UDPLITE_H

/* Check for udplite.h, introduced for UDP-Lite (partial checksum
 * functionality for lossy networks). Supported since Linux 2.6.20.
 */
#ifdef __linux__
#  include <linux/version.h>
#  if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,20)
     /* udplite.h isn't always available even though it's functionality
      * is supported
      */
#    if defined(__has_include) && __has_include(<udplite.h>)
#      define HAVE_UDPLITE_H 1
#    endif
#  endif
#endif

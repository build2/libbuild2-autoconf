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
#    else
       /* udplite.h is missing despite kernel support; define constants manually.
        * see: https://man7.org/linux/man-pages/man7/udplite.7.html
       */
#      define IPPROTO_UDPLITE    136
#      define UDPLITE_SEND_CSCOV 10
#      define UDPLITE_RECV_CSCOV 11
#    endif
#  endif
#endif

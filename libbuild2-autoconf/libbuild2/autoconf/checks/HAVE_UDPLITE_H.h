// HAVE_UDPLITE_H

#undef HAVE_UDPLITE_H

/* Presence of udplite.h, used for UDP-Lite protocol, which offers
 * partial error checking for better performance in lossy networks.
 * Since Linux kernel 2.6.20 (2007)
 */
#ifdef __linux__
#  include <linux/version.h>
#  if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,20)
#    define HAVE_UDPLITE_H 1
#  endif
#endif

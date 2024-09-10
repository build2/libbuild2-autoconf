// HAVE_LINUX_DMA_BUF_H

#undef HAVE_LINUX_DMA_BUF_H

/* Presence of the linux/dma-buf.h header, which provides DMA-BUF
 * support for buffer sharing between different devices in Linux.
 * Linux (kernel 3.3)
 */
#ifdef __linux__
#  include <linux/version.h>
#  if LINUX_VERSION_CODE >= KERNEL_VERSION(3,3,0)
#    define HAVE_LINUX_DMA_BUF_H 1
#  endif
#endif

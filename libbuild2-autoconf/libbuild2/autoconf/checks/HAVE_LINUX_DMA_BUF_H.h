// HAVE_LINUX_DMA_BUF_H

#undef HAVE_LINUX_DMA_BUF_H

/* Check for the <linux/dma-buf.h> header.
 * <linux/dma-buf.h> provides DMA-BUF support for buffer sharing between
 * devices in Linux.
 *
 * Available on Linux/glibc kernel 3.3.0 or later. Not available on Windows or
 * MacOS.
 */
#ifdef __linux__
#  include <linux/version.h>
#  if LINUX_VERSION_CODE >= KERNEL_VERSION(3,3,0)
#    define HAVE_LINUX_DMA_BUF_H 1
#  endif
#endif

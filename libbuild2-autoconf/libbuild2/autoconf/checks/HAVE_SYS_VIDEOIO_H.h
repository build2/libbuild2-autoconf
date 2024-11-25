// HAVE_SYS_VIDEOIO_H : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_SYS_VIDEOIO_H

/* Check for sys/videoio.h presence, which is specific to
 * Solaris and older Unix systems. On Linux, this header is deprecated,
 * and video capture uses linux/videodev2.h instead.
 */
#if (defined(__sun) && defined(__SVR4)) || defined(__sun__)
    #define HAVE_SYS_VIDEOIO_H 1
#elif defined(__linux__)
    #include <linux/version.h>
    #if LINUX_VERSION_CODE < KERNEL_VERSION(2, 6, 27)
        #define HAVE_SYS_VIDEOIO_H 1
    #endif
#endif

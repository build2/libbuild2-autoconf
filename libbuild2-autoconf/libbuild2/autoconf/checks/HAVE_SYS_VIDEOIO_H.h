// HAVE_SYS_VIDEOIO_H : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_SYS_VIDEOIO_H

/* Presence of sys/videoio.h, which provides an interface for controlling video
 * devices. It is often used for video capture devices, particularly on Unix systems.
 * Since Linux Kernel 2.2 (now deprecated), Solaris
 */
#if defined(__linux__) || \
    ((defined(__sun) && defined(__SVR4)) || defined(__sun__))
#  define HAVE_SYS_VIDEOIO_H 1
#endif

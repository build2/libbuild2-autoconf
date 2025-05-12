// HAVE_SYS_HWPROBE_H : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_SYS_HWPROBE_H

/* Presence of sys/hwprobe.h, which is specific to hardware probing
 * interfaces on some Unix-based systems for identifying hardware capabilities.
 * Since Solaris 2.6
 */
#if ((defined(__sun) && defined(__SVR4)) || defined(__sun__))
#  define HAVE_SYS_HWPROBE_H 1
#endif

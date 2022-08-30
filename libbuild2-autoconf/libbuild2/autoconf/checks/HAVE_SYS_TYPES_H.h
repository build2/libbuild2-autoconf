// HAVE_SYS_TYPES_H : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_SYS_TYPES_H
/* Linux only (?) */
#if defined(__linux__)
#  define HAVE_SYS_TYPES_H 1
#endif

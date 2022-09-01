// HAVE_PORT_CREATE : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_PORT_CREATE

/* Since Solaris version ... (?). No version details in manual.
 */
#if (defined(__sun) && defined(__SVR4)) || \
    defined(__sun__)
#  define HAVE_PORT_CREATE 1
#endif

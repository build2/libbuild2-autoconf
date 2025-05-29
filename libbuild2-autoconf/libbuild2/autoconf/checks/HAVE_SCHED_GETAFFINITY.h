// HAVE_SCHED_GETAFFINITY : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_SCHED_GETAFFINITY

/* Presence of the sched_getaffinity() function, which retrieves
 * the CPU affinity of a process (i.e., which CPUs a process can run on).
 * Since glibc 2.3.4, FreeBSD 7.1
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 4) || \
    BUILD2_AUTOCONF_FREEBSD_PREREQ(7, 1)
#  define HAVE_SCHED_GETAFFINITY 1
#endif

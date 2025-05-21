// HAVE_SCHED_GETAFFINITY : BUILD2_AUTOCONF_LIBC_VERSION

#ifndef BUILD2_AUTOCONF_LIBC_VERSION
#  error BUILD2_AUTOCONF_LIBC_VERSION appears to be conditionally included
#endif

#undef HAVE_SCHED_GETAFFINITY

/* Check for the sched_getaffinity() function which retrieves the CPU affinity
 * of a process (i.e., which CPUs a process can run on).
 *
 * Since glibc 2.3.
 */
#if BUILD2_AUTOCONF_GLIBC_PREREQ(2, 3)
#  define HAVE_SCHED_GETAFFINITY 1
#endif

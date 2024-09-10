// HAVE_RDTSC

#undef HAVE_RDTSC

/* Presence of RDTSC (Read Time-Stamp Counter) instruction on x86
 * processors, which reads the number of CPU cycles since the last reset.
 * Since glibc 2.0 (x86), FreeBSD (x86), OpenBSD (x86), NetBSD (x86),
 * MacOS 10.04 (x86)
 */
#if defined(__i386__) || defined(__x86_64__)
#  define HAVE_RDTSC 1
#endif

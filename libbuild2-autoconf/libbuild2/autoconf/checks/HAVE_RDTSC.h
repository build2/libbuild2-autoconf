// HAVE_RDTSC

#undef HAVE_RDTSC

/* Check for the presence of the RDTSC (Read Time-Stamp Counter) instruction,
 * which reads the number of CPU cycles since the last reset.
 * Available on x86 (32-bit and 64-bit) processors.
 */
#if defined(__i386__) || defined(__x86_64__) || \
    defined(_M_IX86) || defined(_M_X64)
#  define HAVE_RDTSC 1
#endif

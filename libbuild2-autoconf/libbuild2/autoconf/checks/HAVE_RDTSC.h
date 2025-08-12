// HAVE_RDTSC

#undef HAVE_RDTSC

/* Check for RDTSC instruction support.
 * RDTSC is an x86 instruction that reads the time-stamp counter.
 *
 * Available on Linux/glibc, MacOS, Windows including MinGW.
 */
#if defined(__i386__)   || \
    defined(__x86_64__) || \
    defined(_M_IX86)    || \
    defined(_M_X64)
#  define HAVE_RDTSC 1
#endif